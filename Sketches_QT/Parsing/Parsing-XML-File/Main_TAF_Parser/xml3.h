#pragma once

#include <QDebug>
#include <QFile>
#include <QObject>
#include <QXmlStreamReader>
#include <tuple>

class xml3 : public QObject {
    Q_OBJECT
  public:
    explicit xml3 (QObject* parent = nullptr);
    ~xml3 ();
    void Read ();

  private:
    QXmlStreamReader xmlReader;
    QMap<QString, QString> mp_Token{};
    QMap<QString, QList<QString>> Token{};
};
