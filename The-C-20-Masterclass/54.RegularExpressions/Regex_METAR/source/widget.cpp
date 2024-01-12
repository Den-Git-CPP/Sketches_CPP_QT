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
    downloader       = new Downloader (this);
    storage_forecast = std::make_unique<Storage_Forecast> ();
    wshow_weather    = new Widget_Show_Weather (this);

    // по нажатию кнопки запускаем получение данных по http
    connect (ui->pushButton_UUWW, &QPushButton::clicked, downloader, [=] () {
        downloader->getData ("UUWW");
    });
    connect (ui->pushButton_UUWW, &QPushButton::clicked, wshow_weather, [=] () {
        //  wShow_Weather->start_close_timer ();
    });
    // по окончанию получения данных считываем данные из буфера
    connect (ui->pushButton_UUDD, &QPushButton::clicked, downloader, [=] () {
        downloader->getData ("UUDD");
    });
    connect (ui->pushButton_UUEE, &QPushButton::clicked, downloader, [=] () {
        downloader->getData ("UUEE");
    });
    connect (downloader, &Downloader::onReady, this, &Widget::getBufferFromDowloanderToSForecast);
}

Widget::~Widget ()
{
    delete ui;
}

void Widget::getBufferFromDowloanderToSForecast ()
{ // забираем буфер и инициализируем класс Storage_Forecast
    if (downloader->buff.data ()) {
        storage_forecast->split (std::move (downloader->buff.data ()));
    }
    wshow_weather->label_name_airport->setText (QString::fromStdString (*storage_forecast->all_Forecast.at (0)->Airport));
    wshow_weather->label_text_raw_METAR->setText (std::move (downloader->buff.data ()));
    std::string DataForecast{};
    for (const auto& elem : storage_forecast->all_Forecast) {
        DataForecast.append (elem->getForecast ());
    }

    wshow_weather->label_text_METAR->setText (QString::fromStdString (DataForecast));
    downloader->buff.clear ();

    wshow_weather->show ();
}

void Widget::ShowSForecast ()
{
    //
}
