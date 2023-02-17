#pragma once

#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QObject>
#include <QXmlStreamReader>

class XML2 : public QObject {
  Q_OBJECT
public:
  explicit XML2(QObject *parent = nullptr);

public slots:
  void Read();
  void read_errors();
  void read_my_warninngs();
  void read_TAF();
  void read_forecast();

private:
  QXmlStreamReader xmlReader;
};
