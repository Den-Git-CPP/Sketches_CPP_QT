#pragma once

#include <QFile>
#include <QWidget>

#include "include/downloader.h"
#include "include/storage_forecast.h"

#include <memory>
QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

  public:
    explicit Widget (QWidget* parent = nullptr);
    ~Widget ();

  private slots:
    void readFile ();
    void create_Storage_Forecast ();

  private:
    Ui::Widget* ui;
    // Объявляем объект класса для скачивания данных по http
    Downloader* downloader{ nullptr };
    // Объявляем объект класса для хранения прогноза погоды
    std::unique_ptr<Storage_Forecast> storage_forecast{ nullptr };
};
