#include "include/downloader.h"

Downloader::Downloader (const QString& name, QObject* parent) : QObject (parent)
{
    airport_name = name;
    // Инициализируем менеджер ...
    manager = new QNetworkAccessManager ();
    // ... и подключаем сигнал о завершении получения данных к обработчику
    // полученного ответа
    connect (manager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
}

void Downloader::getData ()
{
    QUrl url ("https://aviationweather.gov/api/data/taf?ids=" + airport_name + "&format=raw&metar=true");
    // URL, к которому будем
    // получать данные
    QNetworkRequest request; // Отправляемый запрос
    request.setUrl (url);    // Устанавлвиваем URL в запрос
    manager->get (request);  // Выполняем запрос
}

void Downloader::onResult (QNetworkReply* reply)
{
    // Если в процесе получения данных произошла ошибка
    if (reply->error ()) {
        // Сообщаем об этом и показываем информацию об ошибках
        qDebug () << "ERROR";
        qDebug () << reply->errorString ();
    }
    else {
        buff = reply->readAll ();
        // В противном случае создаём объект для работы с файлом
        QFile* file = new QFile ("G:/file.txt");
        // Создаём файл или открываем его на перезапись ...
        if (file->open (QFile::WriteOnly)) {
            file->write (buff); // ... и записываем всю информацию со
                                // страницы в файл
            file->close ();     // закрываем файл
            qDebug () << "Downloading is completed";
            emit onReady ();    // Посылаем сигнал о завершении получения файла
        }
    }
}
