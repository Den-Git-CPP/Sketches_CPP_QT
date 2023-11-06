## Сделано
- Из архива Qt_ibase_driver_6.5.3_MinGW_11.2_64-bit
при сборке в папку Debug а потом и в Deploy с application.exe положить 
папку sqldrivers
файл fbclient.dll

- Из папки Firebird_2_5_64_embedded   
    -папки intl,plugins,udf   
    -все файлы *.dll   
    -скопированный fbembed.dll переименовать fbclient.dll

## Сделано
Ошибка доступа к базе решается через манифест.. или ..
При разработке запускать QCreator от администратора.
Запуск exe от  имени администратора.


===============================   
В разных статьях было дополнительно написано, но на Windows10 достаточно выполнить вышенаписанное, при необходимости проконтролировать...

## Файл   
~~~~
Firebird2Control.cpl  
~~~~
должен быть в папке C:\Windows\System32
~~~~
GDS32.DLL   
~~~~
должен быть в папке C:\Windows\SysWOW64
## Файлы   
~~~~
fbudf.dll    
ib_udf.dll   
fbintl.dll   
icudt30.dll   
icuin30.dll   
icuuc30.dll   
~~~~
должны быть в папке C:\Program   Files\Firebird\Firebird_2_5\UDF   
~~~~
instclient.exe   
fbclient.dll   
~~~~
должны быть в папке C:\Program    Files\Firebird\Firebird_2_5\WOW64   
~~~~  
fbclient.dll   
instsvc.exe   
instreg.exe   
instclient.exe   
ib_util.dll   
fb_lock_print.exe   
fbserver.exe   
fbguard.exe   
gstat.exe   
firebird.msg
~~~~   
должны быть в папке C:\Program  Files\Firebird\Firebird_2_5\bin   
~~~~  
firebirdsql.org.url   
After_Installation.url   
~~~~
должны быть в папке C:\Program Files\Firebird\Firebird_2_5\doc   
~~~~   
IDPLicense.txt   
IPLicense.txt   
~~~~
должны быть в папке C:\Program Files\Firebird\Firebird_2_5   
