site: https://qthelper.ru/работа-с-каталогами-qdir/

# Работа с каталогами QDir

QDir может указывать на файл, используя относительный или абсолютный путь.
~~~~~~~~   
 // Абсолютные путь
QDir("/home/user/Documents")  
QDir("C:/Documents and Settings")  

// Относительный путь
QDir("images/1.png")
QDir("test/1.png")
~~~~~~~~   

-Для определения пути можно использовать методы isRelative() или isAbsolute().    
-Для преобразования из относительный в абсолютный метод makeAbsolute().

Путь к каталогу можно получить с помощью функции path(),  а новый путь — с помощью функции setPath(). 
Абсолютный путь к каталогу определяется путем вызова absolutePath().    
Имя каталога с помощью функции dirName().   
Путь к каталогу также можно изменить с помощью функций cd() и cdUp(), которые работают подобно знакомым командам оболочки.    
Каталоги можно создавать с помощью mkdir(),    
переименовывать с помощью rename(),    
удалять с помощью rmdir().    
Наличия каталога метод exist().    
Свойства с помощью isReadable(), isAbsolute(), isRelative() и isRoot().

Для определения каталога из которого было запущенно приложения следует использовать QApplication::applicationDirPath() или QApplication::applicationFilePath().   

~~~~~~~~~~~~~~~
// Проверка наличии файла    
#include <QDir>    
QDir dir("example.txt");    
if (!dir.exists())    
    qWarning("Не найдено");    
   
// Получение всех файлов в текущем каталоге   
#include <QDir>   
    QDir dir;   
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);    
    dir.setSorting(QDir::Size | QDir::Reversed);    
    QFileInfoList list = dir.entryInfoList();   
    for (int i = 0; i < list.count(); i++) {   
        QFileInfo fileInfo = list.at(i);   
        qDebug() << QString("%1 %2 %3 %4").arg(fileInfo.size(), 10).arg   (fileInfo.fileName()).arg(fileInfo.absoluteFilePath()).arg(fileInfo.suffix());     
    }   
~~~~~~~~~~~~~~~~         

## Метод setFilter() предназначен для фильтрации доступных файлов.
## QDir и setFilter()   
Значение фильтра задается путем объединения значений из следующего списка с использованием побитового оператора ИЛИ:

QDir :: Dirs    Список каталогов   
QDir :: AllDirs Список всех каталогов; не применять фильтры к именам каталогов   
QDir :: Files   Список файлов   
QDir :: Drives  Список дисков (игнорируется в Unix)   
QDir :: NoSymLinks  Не перечислять символические ссылки (игнорируется 
операционными системами, которые не поддерживают символические 
ссылки)   

QDir :: NoDotAndDotDot  Не перечислять специальные записи «.» а также «..»
QDir :: NoDot   Не перечислять специальную запись «.»   
QDir :: NoDotDot    Не перечислять специальную запись «..»   
QDir :: AllEntries  Список каталогов, файлов, дисков и символических ссылок   
QDir :: Readable    Список файлов, для которых у приложения есть доступ для чтения. Читаемое значение должно быть объединено с Dirs или Files   
QDir :: Writable    Список файлов, для которых у приложения есть доступ для записи. Значение Writable должно быть объединено с Dirs или Files   
QDir :: Executable  Список файлов, к которым у приложения есть доступ для выполнения. Исполняемое значение должно быть объединено с Dirs или Files   
QDir :: Hidden  Список скрытых файлов (в Unix, файлы, начинающиеся с «.»)
QDir :: System  Список системных файлов (в Unix включены файлы FIFO, сокеты и файлы устройств; в Windows файлы .lnk)   
QDir :: CaseSensitive   Фильтр должен быть чувствительным к регистру

Созданный по умолчанию QDir не будет отфильтровывать файлы на основе их разрешений, поэтому entryList() и entryInfoList() будут возвращать все файлы, которые доступны для чтения, записи, выполнения или любой комбинации этих первых трех фильтров.


## QDir и setSorting()
Метод setSorting() задает параметры сортировки.

Данный метод поддерживает одну сортировку по следующим параметрам:

QDir::Name  Сортировать по имени   
QDir::Time  Сортировать по времени (время модификации)   
QDir::Size  Сортировать по размеру файла   
QDir::Type  Сортировка по типу файла (расширение)


# Решения

Получение текущего каталога с помощью QDir
~~~~~~~~~~~~~~~
QDir currentDir;
qDebug() << "Текущий путь:" << currentDir.absolutePath();
~~~~~~~~~~~~~~~
Изменение текущего каталога с помощью QDir
~~~~~~~~~~~~~~~
QDir dir;
if (dir.cd("Documents")) {
    qDebug() << "Перешли в каталог:" << dir.absolutePath();
} else {
    qDebug() << "Не удалось перейти в папку 'Documents'";
}
~~~~~~~~~~~~~~~
Получение списка файлов с помощью QDir
~~~~~~~~~~~~~~~
QDir dir("/home/user/Documents");
QStringList files = dir.entryList(QDir::Files);
for (const QString &file : files) {
    qDebug() << "Файл:" << file;
}
~~~~~~~~~~~~~~~
Получение только папок с помощью QDir
~~~~~~~~~~~~~~~
QDir dir("/home/user");
QStringList folders = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
for (const QString &folder : folders) {
    qDebug() << "Папка:" << folder;
}
~~~~~~~~~~~~~~~
Фильтрация по расширению с помощью QDir
~~~~~~~~~~~~~~~
QDir dir("/home/user/images");
QStringList filters;
filters << "*.jpg" << "*.png";
dir.setNameFilters(filters);
QStringList images = dir.entryList(QDir::Files);
for (const QString &img : images) {
    qDebug() << "Изображение:" << img;
}
~~~~~~~~~~~~~~~
Создание новой папки с помощью QDir
~~~~~~~~~~~~~~~
QDir dir("/home/user");
if (dir.mkdir("NewFolder")) {
    qDebug() << "Папка создана.";
} else {
    qDebug() << "Не удалось создать папку.";
}
~~~~~~~~~~~~~~~
Удаление папки с помощью QDir
~~~~~~~~~~~~~~~
QDir dir("/home/user/NewFolder");
if (dir.removeRecursively()) {
    qDebug() << "Папка удалена.";
} else {
    qDebug() << "Ошибка при удалении.";}
~~~~~~~~~~~~~~~
Проверка существования файла или папки с помощью QDir
~~~~~~~~~~~~~~~
QDir dir("/home/user/Documents");
if (dir.exists()) {
    qDebug() << "Каталог существует.";
} else {
    qDebug() << "Каталог не найден.";
}
~~~~~~~~~~~~~~~
Построение абсолютного и относительного пути с помощью QDir
~~~~~~~~~~~~~~~
QDir dir("/home/user");
QString absolutePath = dir.absoluteFilePath("Documents/file.txt");
QString relativePath = dir.relativeFilePath("/home/user/Documents/file.txt");
qDebug() << "Абсолютный путь:" << absolutePath;
qDebug() << "Относительный путь:" << relativePath;
~~~~~~~~~~~~~~~
Получение только читаемых файлов с помощью QDir
~~~~~~~~~~~~~~~
QDir dir("/home/user");
QStringList list = dir.entryList(QDir::Files | QDir::Readable, QDir::Name);
for (const QString &file : list) {
    qDebug() << "Читаемый файл:" << file;
}
~~~~~~~~~~~~~~~
Флаги и фильтры

Флаги QDir::Filters:   
QDir::Files — только файлы   
QDir::Dirs — только каталоги   
QDir::Hidden — скрытые файлы/папки   
QDir::NoDotAndDotDot — исключить . и ..   
   
Сортировка QDir::SortFlags:
QDir::Name — по имени   
QDir::Time — по дате изменения   
QDir::Size — по размеру   
QDir dir("/home/user");   
QStringList sortedFiles = dir.entryList(QDir::Files, QDir::Time);   


Расширенная фильтрация файлов Qt: за пределами QDir::setNameFilters()   
Функция QDir::setNameFilters() — это мощный инструмент в Qt, который позволяет фильтровать содержимое каталога. Она принимает QStringList подстановочных знаков, таких как *.txt или image_*.jpg, и возвращает только соответствующие файлы. Это очень удобно для таких задач, как открытие диалогового окна выбора файла или вывод списка файлов определённого типа в папке.   
По умолчанию QDir чувствителен к регистру. Это означает, что фильтр для *.JPG не будет соответствовать файлу с именем my_photo.jpg.

Устранение неполадок   
Вам нужно явно указать QDir игнорировать регистр. Это можно сделать с помощью флагов QDir::CaseSensitive или QDir::CaseInsensitive.   
Пример кода 
~~~~~~~~~~~~~~~ 
// Problematic code (won't match "readme.txt")   
QDir dir("/path/to/my/folder");   
dir.setNameFilters(QStringList("*.TXT"));  
   
// Corrected code (case-insensitive)   
QDir dir("/path/to/my/folder");   
dir.setNameFilters(QStringList("*.TXT"));   
dir.setFilter(QDir::Files | QDir::NoDotAndDotDot); // Make sure you're filtering for files   
dir.setSorting(QDir::Name);   
dir.setFilter(dir.filter() | QDir::CaseInsensitive); // Add this flag  
~~~~~~~~~~~~~~~
Распространённая ошибка — просто задать фильтры имён и ожидать, что QDir автоматически определит, что вы хотите видеть файлы. Вам также нужно задать QDir::Filter, чтобы указать, какие записи вы хотите видеть (например, файлы, каталоги, символические ссылки).  

Устранение неполадок  
Всегда объединяйте setNameFilters() с вызовом setFilter().   

Пример кода  
~~~~~~~~~~~~~~~ 
// Problematic code (won't work as expected)  
QDir dir("/path/to/my/folder");   
dir.setNameFilters(QStringList("*.txt"));  
// You need to do more here!  
   
// Corrected code  
QDir dir("/path/to/my/folder");  
dir.setNameFilters(QStringList("*.txt"));  
dir.setFilter(QDir::Files | QDir::NoDotAndDotDot); // This is key!  
QStringList files = dir.entryList();  
~~~~~~~~~~~~~~~   
Для более сложной фильтрации вместо setNameFilters() можно использовать регулярные выражения. Регулярные выражения гораздо мощнее и гибче, чем простые шаблоны с подстановочными знаками.  
  
Как это использовать  
Класс QRegExp можно использовать для более сложного сопоставления с образцом. Хотя QDir напрямую не поддерживает регулярные выражения для фильтрации, вы можете выполнить фильтрацию самостоятельно после получения списка всех файлов.   
   
Пример кода   
~~~~~~~~~~~~~~~   
// Let's find files that start with "data" and end with a number.   
// For example: "data_report_1.txt" or "data_results_23.csv"   
   
QDir dir("/path/to/my/folder");   
QStringList allFiles = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);   
QRegExp regExp("^data.*\\d+\\.(txt|csv)$", Qt::CaseInsensitive);   
QStringList filteredFiles;   
   
for (const QString& file : allFiles) {  
    if (regExp.exactMatch(file)) {   
        filteredFiles.append(file);  
    }  
}  
~~~~~~~~~~~~~~~   

//Получить окончательное время изменения всех файлов в папке
~~~~~~~~~~~~~~~   

QDateTime GetLastmodifiedTime(QString catalog)
{
    QDir dir(catalog);
    //Время нахождения конкретного файла в каталоге
    //Получает только файлы из этого каталога, отсортированные по времени последнего изменения
    QFileInfoList fileList = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files, QDir::Time);

    QDateTime lastModifiedTime(QDate(0, 0, 0));
    if (fileList.isEmpty() == false)
    {
        lastModifiedTime = fileList.first().lastModified().toLocalTime();
    }

    //Папки в этом каталоге
    fileList = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs, QDir::Time); ///Получает только файлы из этого каталога, отсортированные по времени последнего изменения

    if (fileList.isEmpty() == false)
    {
        for (int i = 0; i < fileList.size(); i++)
        {
            QString newCatalog = fileList.at(i).absoluteFilePath();
            QDateTime temp = GetLastmodifiedTime(newCatalog);

            if (lastModifiedTime < temp)
            {
                lastModifiedTime = temp;
            }
        }
    }

    return lastModifiedTime;
}
~~~~~~~~~~~~~~~   

## QDir::rename():особенности

Функция QDir::rename(const QString &oldName, const QString &newName) в Qt используется для переименования файла или подкаталога,    
расположенного в каталоге, который в данный момент представляет объект QDir.   
   
Для этого требуется два аргумента   
oldName - Имя существующего файла или каталога в пути QDir's.   
newName -Новое имя для этого файла или каталога.   
В случае успеха возвращается true, а в случае ошибки — false.   
   
Чтобы переименовать каталог, представленный объектом QDir (например, изменить /path/to/old_dir на /path/to/new_dir), используйте     
site: https://runebook.dev/en/docs/qt/qdir/rename
~~~~~~~~~~~~~~~   

#include <QFile>
#include <QDir>
#include <QDebug>

bool renameCurrentDir(QDir& dir, const QString& newName) {
    QString oldPath = dir.absolutePath();
    // Get the path for the new directory name.
    // We navigate up to the parent and then add the new name.
    QString newPath = dir.path() + QDir::separator() + ".." + QDir::separator() + newName;
    newPath = QDir::cleanPath(newPath); // Normalize the path (removes ".." etc.)

    // Use QFile::rename() with absolute paths for the directory itself
    if (QFile::rename(oldPath, newPath)) {
        // IMPORTANT: Update the QDir object's path so it still points to the directory!
        dir.setPath(newPath);
        qDebug() << "Directory successfully renamed to:" << dir.path();
        return true;
    } else {
        qWarning() << "Failed to rename directory from" << oldPath << "to" << newPath;
        return false;
    }
}
// ... call it like this:
// QDir myDir("/path/to/test_dir");
// renameCurrentDir(myDir, "renamed_test_dir");
~~~~~~~~~~~~~~~   
   
Надёжная и понятная операция перемещения (особенно для файлов, перемещаемых между каталогами или дисками), вы можете реализовать её с помощью QFile.    

~~~~~~~~~~~~~~~   
#include <QFile>
#include <QDebug>

bool moveFileRobustly(const QString& oldPath, const QString& newPath) {
    if (QFile::rename(oldPath, newPath)) {
        // Try simple rename first (most efficient)
        return true;
    }

    // If rename fails, fall back to copy and delete
    qWarning() << "Rename failed. Attempting copy/delete fallback.";
    if (QFile::copy(oldPath, newPath)) {
        if (QFile::remove(oldPath)) {
            qDebug() << "Successfully moved file via copy/delete.";
            return true;
        } else {
            qWarning() << "ERROR: Copy succeeded, but failed to delete original file!";
            // Handle cleanup/error logging here
            return false;
        }
    } else {
        qWarning() << "ERROR: Failed to copy file.";
        return false;
    }
}
~~~~~~~~~~~~~~~   

Example2
~~~~~~~~~~~~~~~  
bool fileTransferAndRenameDB (const QString& oldPath, const QString& newPath)
{
    // Попробуем сначала простое переименование (самое эффективное)
    if (QFile::rename (oldPath, newPath)) {
        return true;
    }
    else {
        // Если переименование не удалось, возвращаемся к копированию и удалению
        qWarning () << "Rename failed. Attempting copy/delete as a backup.";

        if (QFile::copy (oldPath, newPath)) {
            if (QFile::remove (oldPath)) {
                qDebug () << "File successfully moved by copy/delete.";
                return true;
            }
            else {
                qWarning () << "ERROR: Copy completed successfully, but could not delete the source file!";
                // Handle cleanup/error logging here
                return false;
            }
        }
        else {
            qWarning () << "ERROR: Failed to copy file.";
            return false;
        }
    }
}
~~~~~~~~~~~~~~~  
~~~~~~~~~~~~~~~  
    QStringList sortedFiles{};
    sortedFiles << ui->l_Edit_1DBF->text () 
                << ui->l_Edit_2DBF->text ();

    // сравнить по дате переименовать
    for (const QString& files : sortedFiles) {
        // просмотрели инфу
        if (!files.isEmpty ()) {
            QFileInfo info (files);
            // время последнего модифицирования
            QDateTime lastModifiedTime = info.lastModified ().toLocalTime ();

            // абсолютный старый путь до файла
            QString oldPath_DB = info.absoluteFilePath ();
            // нормализовали путь
            oldPath_DB = QDir::cleanPath (oldPath_DB);
            // путь где будет новый файл
            QString newPath_DB = QApplication::applicationDirPath () + QDir::separator () + "DB" + QDir::separator () + info.baseName ()
                                 + lastModifiedTime.toString ("_ddMMyyyy_hhmmss.") + info.completeSuffix ();
            // нормализовали путь
            newPath_DB = QDir::cleanPath (newPath_DB);
            // пытаемся скопровать файл
            if (!fileTransferAndRenameDB (oldPath_DB, newPath_DB)) {
                qWarning () << "ОШИБКА:------------\n";
            }
            paths_Db << std::move (newPath_DB);
        }
    }

~~~~~~~~~~~~~~~  

Example 3    
Рекурсивное копирование
~~~~~~~~~~~~~~~  
 bool copyRecursively(QString sourceFolder, QString destFolder)
    {
     bool success = false;
    // путь до папки источника
    QDir sourceDir (sourceFolder);
    // если источника олшибка
    if (!sourceDir.exists ()) {
        return false;
    }
    // путь до папки назначения
    QDir destDir (destFolder);

    // если его нет -создать его
    if (!destDir.exists ()) {
        destDir.mkdir (destFolder);
    }

    // Копирование файлов
    // Получением списка файлов
    QStringList files = sourceDir.entryList (QDir::Files);

    for (int i = 0; i < files.count (); i++) {
        QString srcName  = sourceFolder + QDir::separator () + files [i];
        QString destName = destFolder + QDir::separator () + files [i];
        // копирование файла
        success = QFile::copy (srcName, destName);
        if (!success) {
            qWarning () << "ERROR: Failed to copy file.";
            return false;
        }
    }

    files.clear ();
    // Копирование каталогов
    files = sourceDir.entryList (QDir::AllDirs | QDir::NoDotAndDotDot); //
    for (int i = 0; i < files.count (); i++) {
        QString srcName  = sourceFolder + QDir::separator () + files [i];
        QString destName = destFolder + QDir::separator () + files [i];
        success          = copyRecursively (srcName, destName);
        if (!success) {
            return false;
        }
    }

    return true;
    }
~~~~~~~~~~~~~~~     

