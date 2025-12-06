site https://qthelper.ru/qfileinfo-получение-информации-о-файлах/

QFileInfo — отличный способ быстро и безопасно получить метаинформацию о любом файле или каталоге. Полезен при построении интерфейсов для работы с файлами, логов, архиваторов и других систем.   

Подключение QFileInfo
~~~~~~~~  
#include <QFileInfo>
#include <QDebug>
~~~~~~~~  
Основные свойства QFileInfo
~~~~~~~~  
QFileInfo info("example.txt");
qDebug() << "Имя файла:" << info.fileName();
qDebug() << "Путь:" << info.absolutePath();
qDebug() << "Полный путь:" << info.absoluteFilePath();
qDebug() << "Размер (байт):" << info.size();
qDebug() << "Расширение:" << info.suffix();
~~~~~~~~  
Проверка типа файла с помощью QFileInfo
~~~~~~~~  
if (info.exists()) {
    if (info.isFile()) {
        qDebug() << "Это файл.";
    } else if (info.isDir()) {
        qDebug() << "Это папка.";
    }
}
~~~~~~~~  
Дата создания и изменения
~~~~~~~~  
qDebug() << "Создан:" << info.created().toString();
qDebug() << "Изменён:" << info.lastModified().toString();
qDebug() << "Последний доступ:" << info.lastRead().toString();
~~~~~~~~  
Абсолютный и относительный путь
~~~~~~~~  
QDir baseDir("/home/user");
QFileInfo info(baseDir, "documents/report.pdf");
qDebug() << "Относительно /home/user:" << info.filePath();
qDebug() << "Абсолютный путь:" << info.absoluteFilePath();
~~~~~~~~  
Проверка доступности с помощью QFileInfo
~~~~~~~~  
if (info.isReadable()) qDebug() << "Файл доступен для чтения.";
if (info.isWritable()) qDebug() << "Файл доступен для записи.";
if (info.isExecutable()) qDebug() << "Файл исполняемый.";
~~~~~~~~  
Полезные методы QFileInfo
 
Метод	            Назначение
fileName()	        Имя файла   
absoluteFilePath()	Полный путь   
size()	            Размер файла   
isFile(), isDir()	Проверка типа   
lastModified()	    Время изменения   
exists()	        Существует ли файл   
suffix()	        Расширение   
created()	        Время создания  

Функция QFileInfo::birthTime() пытается получить время создания (время, когда файл был создан изначально) файла или каталога. Она возвращает объект QDateTime.


~~~~~~~~  
#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filePath = "my_file.txt"; // Replace with your file path
    QFileInfo fileInfo(filePath);

    if (fileInfo.exists()) {
        // Get the last modified time - This is highly reliable!
        QDateTime modifiedTime = fileInfo.lastModified();
        
        qDebug() << "File:" << filePath;
        qDebug() << "Last Modified Time:" << modifiedTime.toString(Qt::ISODate);

        // Check the birth time just in case (for comparison)
        QDateTime birthTime = fileInfo.birthTime();
        if (birthTime.isValid()) {
            qDebug() << "Birth Time (if supported):" << birthTime.toString(Qt::ISODate);
        } else {
            qDebug() << "Birth Time: Not available or invalid on this system.";
        }
    } else {
        qDebug() << "Error: File not found!";
    }

    return 0;
}
~~~~~~~~     
   
Если вам необходимо указать время создания и вы работаете в системе, где это возможно (например, в Windows), всегда проверяйте, является ли возвращаемое значение QDateTime действительным.     

~~~~~~~~     
// Inside a function that takes a QFileInfo object
void showCreationTime(const QFileInfo& info)
{
    QDateTime creationTime = info.birthTime();

    if (creationTime.isValid()) {
        qDebug() << "Creation Time (Birth Time):" << creationTime.toString(Qt::SystemLocaleDate);
    } else {
        qDebug() << "Birth Time not found. Falling back to Modification Time...";
        
        // Fallback option: Use the last modification time as a substitute
        QDateTime fallbackTime = info.lastModified();
        qDebug() << "Last Modified Time:" << fallbackTime.toString(Qt::SystemLocaleDate);
    }
}
~~~~~~~~     
Для приложений, которым абсолютно необходимо отслеживать время создания файла с точки зрения вашего приложения, единственным по-настоящему кроссплатформенным и надёжным методом является самостоятельное отслеживание создания файла.
Создайте файл.

- Немедленно запишите текущее системное время (QDateTime::currentDateTime()).   
- Сохраните эту временную метку в надёжном месте (например, в базе данных, INI-файле или в файле метаданных рядом с созданным файлом).   
- Это гарантирует, что временная метка будет неизменной независимо от ограничений файловой системы базовой операционной системы.   

~~~~~~~~   
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

// Function to create a file and record its creation time
void createAndTrackFile(const QString& fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "This is my new file content.\n";
        file.close();

        // 1. Get the current time when *we* created the file
        QString creationStamp = QDateTime::currentDateTime().toString(Qt::ISODate);

        // 2. Write this stamp to a separate, dedicated metadata file
        QFile metaFile(fileName + ".meta");
        if (metaFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream metaOut(&metaFile);
            metaOut << "creation_time=" << creationStamp << "\n";
            metaFile.close();
            qDebug() << "File and metadata created successfully!";
            qDebug() << "Recorded Creation Time:" << creationStamp;
        }
    } else {
        qDebug() << "Error creating file!";
    }
}
~~~~~~~~   