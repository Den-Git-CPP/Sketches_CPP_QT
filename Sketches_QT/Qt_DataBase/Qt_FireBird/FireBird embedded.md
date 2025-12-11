# Как приготовить FireBird embedded.    
   
Начиная с версии 2.5, FB может обеспечить совместный доступ к одному файлу БД из разных процессов.   
Используем Firebird embedded как обычный сервер.      
Для работы с файлом базы по «embedded» протоколу, клиентское приложение в строке коннекта должно указать лишь путь к файлу базы. При «embedded» коннекте не требуется логин или пароль.      
   
##Правильно:     
D:\MyFiles\MyBase.fdb       
   
##Неправильно:     
Localhost:D:\MyFiles\MyBase.fdb     
   
Если вы указать в строке коннекта сетевой путь, то Firebird embedded превратится в обыкновенную клиентскую библиотеку, обеспечивающую доступ к удаленному не-ebmbedded серверу Firebird.     
-Однако  №1:     
Некоторые клиентские утилиты и библиотеки могут требовать их наличия (например, будет появляться окно диалога с требованием указать логин и пароль) – в этом случае нужно указывать «хоть что-то».     
-Однако  №2:      
SQL привилегии (права на объекты, «гранты») продолжают действовать. Таким образом, при «embedded» логине пользователь должен соответствовать выданным правам. (при коннекте с username=SYSDBA, таким образом, получим доступ ко всем объектам).    
   
## FB 2.5
Набор необходимых файлов:    
http://www.firebirdsql.org/en/firebird-2-5/     
последнюю версию архива с Firebird embedded,    
https://github.com/FirebirdSQL/firebird/releases/download/R2_5_8/Firebird-2.5.8.27089-0_Win32_embed.zip   
   
Далее:       
-Загрузите и разархивируйте встроенный комплект Firebird в отдельную папку.       
Для справки, минимально необходимые файлы для Firebird 2.5:       
fbembed.dll      
Firebird.msg      
ib_util.dll     
icudt30.dll     
icuin30.dll     
icuuc30.dll     
IDPLicense.txt      
IPLicense.txt      
Microsoft.VC80.CRT.манифест      
msvcp80.dll      
msvcr80.dll      
   
-Удаляем папку doc.     
-Клиентская библиотека    
fbclient.dll/gds32.dll , файлы .dll и .manifest должны быть доступны клиентскому приложению в соответствии с правилами пути поиска, используемых Windows для обнаружения библиотеки DLL:     
https://msdn.microsoft.com/ru-ru/library/7d83bc18.aspx  

Например, клиентское приложение должно находиться в той же папке, что и клиентская библиотека (fbclient.dll/gds32.dll),  
Или путь должен быть указан "глобально", в переменной окружения PATH.   
Или "локально" (т.е., только для данного процесса) - с помощью функции API SetEnviromentVariable. 
Если нет возможности указывать клиентскую библиотеку явно (при работе с ibx, например), следует переименовать файл fbembed.dll в fbclient.dll или в gds32.dll

## FB 3.0
Многое не так, как в FB 2.5, читаем «ЕЩЕ БОЛЕЕ» внимательно.

Где брать файлы для Firebird embedder 3.0?   
Отдельного пакета для Firebird Embedded больше нет.

Файлы берем вот здесь:   
 https://www.Firebirdsql.org/en/Firebird-3-0/    

Ищем “Zip kit for manual/custom install”, например: https://github.com/FirebirdSQL/Firebird/releases/download/R3_0_3/Firebird-3.0.3.32900-0_Win32.zip

Скачиваем, распаковываем в отдельную папку.   
-Удаляем подпапки doc, examples, system32, include, lib, misc, help.   
-Удаляем все файлы с расширениями «exe» и «bat». Если вы уже знаете, для чего нужны эти «exe» - шники, и они вам действительно нужны - их удалять не следует. Например, оставить gfix, gstat, gbak, isql и nbackup.    
-Удаляем fbrmclib.dll, fbtrace.conf, security3.fdb.   
-Удаляем в папке plugis все файлы, кроме файла engine12.dll.   
Возможно, придется переименовать клиентскую библиотеку: fbclient.dll переименовать в gds32.dll.    
Клиентская библиотека (fbclient.dll/gds32.dll) должна быть доступна клиентскому приложению в соответствии с правилами пути поиска, используемых Windows для обнаружения библиотеки DLL: https://msdn.microsoft.com/ru-ru/library/7d83bc18.aspx

Но все это пока не обеспечивает одновременный доступ к файлу базы из разных процессов.
Обеспечение одновременного доступа к файлу базы из разных процессов.

Открываем в текстовом редакторе файл Firebird.conf, находим строку:
```
#ServerMode = Super   
```
Редактируем ее, должно получиться:   
```
ServerMode = Classic
```
## Замечания.
Замечание 1.  
Совместное использование в одном приложении FB embedded 3.0 (и 4.0) одновременно с другими FB (embedded или нет) иногда невозможно. Дело в том, что FB embedded 3.0 загружает engine12.dll (engine12.dll в FB 4.0), которая, в свою очередь, «статически» подгружает некоторые функции из fbclient.dll. Если загрузится «не своя» fbclient.dll, этих функций там может не оказаться.

По этой же причине нельзя переименовывать fbclient.dll в FB embedded 3.0 (4.0).

Замечание 2.   
Перед завершением приложения, использующего Firebird embedded, следует вызвать функцию fb_shutdown().    
Подробности:   
https://firebirdsql.org/file/documentation/release_notes/html/en/2_5/rnfb25-apiods-api.html

Вот так функция fb_shutdown() выглядит    
с точки зрения «сишников»:
```
int fb_shutdown(unsigned int timeout, const int reason);
```
с точки зрения «дельфистов»:   
  ```
  fb_shutdown: function(timeout: Cardinal; const reason: Integer): Integer; stdcall;
  ```

Эта функция живет в клиентской библиотеке (fbembed.dll). Приложение перед своим завершением (точнее, перед выгрузкой клиентской библиотеки) должно вызвать функцию fb_shutdown(). Если нет доступа к хэндлу загруженной библиотеки, следует отдельно загрузить эту библиотеку (для получения хэндла), запросить адрес функции fb_shutdown() и вызвать ее с параметрами (0, 1). Потом выполнить выгрузку библиотеки.

Пред вызовом функции fb_shutdown() следует сохранить управляющее состояние FPU, а затем – восстановить его. Обычно клиентские библиотеки делают это самостоятельно, но в данном случае придется делать все руками. Разработчики FireBird утверждают, что сие уже не требуется. Тем не менее, зафиксированы случаи проблем с FPU, данное действие позволяет обойти их.

Примерный код (Delphi):
```
procedure fbShutdown(const string aLibraryName);
var
  fbClientLibHandle: Cardinal;
  fb_shutdown: function(timeout, : Cardinal; const reason: Integer): Integer; stdcall;
  fSaved8087CW: Word;
begin
  // Деинициализация коннекта. Метод должен быть вызван перед завершением приложения
  // !!! не в секции finalization
  fSaved8087CW := Get8087CW();
  try
    fbClientLibHandle := LoadLibrary(PChar(aLibraryName));
    if fbClientLibHandle > 32 then begin
      fb_shutdown := GetProcAddress(fbClientLibHandle, 'fb_shutdown');
      if Assigned(fb_shutdown) then
        fb_shutdown(0, 1);
      FreeLibrary(fbClientLibHandle);
    end;
  finally
    Set8087CW(fSaved8087CW)
  end;
end;
```
## Замечание. 
fb_shutdown() следует вызывать лишь после того, как был выполнен минимум один коннект к базе или к сервису (даже если всего лишь версию клиента запросите). Разработчики Firebird утверждают, что и этот глюк был исправлен.
