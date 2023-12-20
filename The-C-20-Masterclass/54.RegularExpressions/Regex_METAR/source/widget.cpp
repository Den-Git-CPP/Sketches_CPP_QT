#include "include/widget.h"
#include "source/ui_widget.h"

Widget::Widget (QWidget* parent) : QWidget (parent), ui (new Ui::Widget)
{
    ui->setupUi (this);
    // настройки окна widget
    this->setWindowTitle ("Погода");
    // Значок для окна
    QIcon* icon1 = new QIcon (":/resource/meteo.ico");
    this->setWindowIcon (*icon1);
    // Инициализируем Downloader
    downloader = new Downloader (this);
    // по нажатию кнопки запускаем получение данных по http
    connect (ui->pushButton_UUWW, &QPushButton::clicked, downloader, [=] () {
        downloader->getData ("UUWW");
    });
    // по окончанию получения данных считываем данные из буфера
    connect (ui->pushButton_UUDD, &QPushButton::clicked, downloader, [=] () {
        downloader->getData ("UUDD");
    });
    connect (ui->pushButton_UUEE, &QPushButton::clicked, downloader, [=] () {
        downloader->getData ("UUEE");
    });

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
    qDebug () << "end";
}
