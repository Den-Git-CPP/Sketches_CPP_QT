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
    explicit Downloader (const QString& name, QObject* parent = nullptr);
    QByteArray buff{};
  signals:
    void onReady ();

  public slots:
    void getData ();                      // Метод инициализации запроса на получение данных
    void onResult (QNetworkReply* reply); // Слот обработки ответа о полученных данных

  private:
    QNetworkAccessManager* manager; // менеджер сетевого доступа
    QString airport_name{};
};
