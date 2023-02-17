#pragma once

#include <QFile>
#include <QWidget>

#include "downloader.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
  Q_OBJECT

public:
  explicit Widget(QWidget* parent = nullptr);
  ~Widget();

private slots:
  void readFile();

private:
  Ui::Widget* ui;
  // Объявляем объект класса для скачивания данных по http
  Downloader* downloader;
};
