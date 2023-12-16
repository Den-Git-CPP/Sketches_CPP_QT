#include "include/widget.h"
#include "source/ui_widget.h"

Widget::Widget (QWidget* parent) : QWidget (parent), ui (new Ui::Widget)
{
    ui->setupUi (this);
    downloader = new Downloader ("UUWW"); // Инициализируем Downloader
                                          // по нажатию кнопки запускаем получение данных по http
    connect (ui->pushButton, &QPushButton::clicked, downloader, &Downloader::getData);
    // по окончанию получения данных считываем данные из буфера
    connect (downloader, &Downloader::onReady, this, &Widget::create_Storage_Forecast);
}

Widget::~Widget ()
{
    delete ui;
}

void Widget::readFile () {}

void Widget::create_Storage_Forecast ()
{
    // создаем и инициализируем класс Storage_Forecast
    storage_forecast = std::make_unique<Storage_Forecast> (std::move (downloader->buff.toStdString ()));
    // разбираем прогноз
    storage_forecast->split ();
    qDebug () << "s";
}
