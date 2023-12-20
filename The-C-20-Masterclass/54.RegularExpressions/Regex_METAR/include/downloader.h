#pragma once
#include <QDebug>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QUrl>
#include <QString>
#include <QByteArray>

class Downloader : public QObject {
    Q_OBJECT
  public:
    explicit Downloader (QObject* parent = nullptr);
    QByteArray buff{};
  signals:
    void onReady ();

  public slots:
    void getData (const QString& name);   // Метод инициализации запроса на получение данных
    void onResult (QNetworkReply* reply); // Слот обработки ответа о полученных данных

  private:
    void clearDownloader (QObject* parent = nullptr);
    QNetworkAccessManager* manager; // менеджер сетевого доступа
    QString airport_name{};
};
