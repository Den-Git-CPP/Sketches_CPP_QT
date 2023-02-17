#pragma once
#include <QDebug>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QUrl>

class Downloader : public QObject
{
  Q_OBJECTF
public:
  explicit Downloader(QObject* parent = nullptr);

signals:
  void onReady();

public slots:
  void getData(); // Метод инициализации запроса на получение данных
  // Слот обработки ответа о полученных данных
  void onResult(QNetworkReply* reply);

private:
  QNetworkAccessManager* manager; // менеджер сетевого доступа
};
