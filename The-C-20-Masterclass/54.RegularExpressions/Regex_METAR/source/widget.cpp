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

    timer_show_weather = new QTimer(this);
    //timer_show_weather->setInterval(600000); // интервал 10 мин Qtimer 1000 ->1сек
    timer_show_weather->setInterval(60000); // интервал 10 мин Qtimer 1000 ->1сек
    connect(timer_show_weather, &QTimer::timeout, this, &Widget::Show_weather);
    timer_show_weather->start();

}

Widget::~Widget ()
{
    delete ui;
}

void Widget::getBufferFromDowloanderToSForecast ()
{ // забираем буфер и инициализируем класс Storage_Forecast
     wshow_weather    = new Widget_Show_Weather (this);
    if (downloader->buff.data ()) {
        storage_forecast->split (std::move (downloader->buff.data ()));
    }
    wshow_weather->label_name_airport->setText (QString::fromStdString (*storage_forecast->all_Forecast.at (0)->Airport));
    wshow_weather->label_text_raw_METAR->setText (QString::fromStdString(storage_forecast->RawMETAR));
    wshow_weather->label_text_raw_TAF->setText (QString::fromStdString(storage_forecast->RawTAF));
    wshow_weather->label_text_METAR->setText(QString::fromStdString (storage_forecast->all_Forecast.at(0)->getForecast()));
 //  std::string DataForecast{};
 //   for(auto i=1;i<storage_forecast->all_Forecast.size();++i){
 //       DataForecast.append (storage_forecast->*all_Forecast.at(i)->getForecast());
 //       }
 //   wshow_weather->label_text_TAF->setText (std::move(QString::fromStdString (DataForecast)));
 //   //
    downloader->buff.clear ();
    wshow_weather->show ();
}

void Widget::Show_weather()
{   switch (position_selection) {
        case 1:
            emit ui->pushButton_UUWW->clicked();
            wshow_weather->move(10, 0);
            position_selection++;
            break;
        case 2:
            emit ui->pushButton_UUDD->clicked();
            wshow_weather->move(300, 0);
            position_selection++;
            break;
        case 3:
            emit ui->pushButton_UUEE->clicked();
            wshow_weather->move(600, 0);
            position_selection = 1;
            break;
    }
}

