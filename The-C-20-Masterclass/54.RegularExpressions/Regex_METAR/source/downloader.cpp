#include "include/downloader.h"

Downloader::Downloader (QObject* parent) : QObject (parent)
{ // Инициализируем менеджер ...
    manager = new QNetworkAccessManager (this);
    // ... и подключаем сигнал о завершении получения данных к обработчику
    // полученного ответа
    connect (manager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
}

void Downloader::getData (const QString& name)
{
    // airport_name = name;
    QUrl url ("https://aviationweather.gov/api/data/taf?ids=" + name + "&format=raw&metar=true");
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
        // QFile* file = new QFile ("C:\\QTPROJECT\\file.txt");
        //// Создаём файл или открываем его на перезапись ...
        // if (file->open (QFile::WriteOnly)) {
        //    file->write (reply->readAll ()); // ... и записываем всю информацию со
        //                                     // страницы в файл
        //    file->close ();                  // закрываем файл
        //                     // Посылаем сигнал о завершении получения файла
        //}
        // В противном случае создаём буфер
        buff = reply->readAll ();
        // сигнал забрать буффер
        emit onReady ();
    }
    reply->deleteLater ();
}
