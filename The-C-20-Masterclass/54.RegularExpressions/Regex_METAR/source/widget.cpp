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
    wshow_weather2   = new Widget_Show_Weather_2 ();

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
    connect (downloader, &Downloader::onReady, this, &Widget::getBufferFromDowloanderToSForecast);
    connect (downloader, &Downloader::ErrorDownload, this, [=] () {
        Show_Error (downloader->ErrorString);
    });

    // запуск запроса по умолчанию
    timer_show_weather = new QTimer (this);
    timer_show_weather->setInterval (600000); // интервал 10 мин Qtimer 1000 ->1сек
    connect (timer_show_weather, &QTimer::timeout, this, [=] () {
        Show_weather ();
    });
    //"Start timer_show_weather" << QTime::currentTime ().toString ();
    timer_show_weather->start ();
}

Widget::~Widget ()
{
    delete ui;
}

void Widget::getBufferFromDowloanderToSForecast ()
{ // забираем буфер и инициализируем класс Storage_Forecast
    if (downloader->buff->data ()) {
        storage_forecast->split (std::move (downloader->buff->data ()));
    }

    // название аэропорта
    wshow_weather2->set_Label_Name_Airport (std::move (std::move (*storage_forecast->all_Forecast.at (0)->Airport)));
    // название METAR
    wshow_weather2->set_Label_Text_Raw_METAR (std::move (std::move (storage_forecast->RawMETAR)));
    wshow_weather2->set_Label_Text_METAR (std::move (std::move (storage_forecast->all_Forecast.at (0)->getForecast ())));
    // название TAF
    wshow_weather2->set_Label_Text_Raw_TAF (std::move (std::move (storage_forecast->RawTAF)));
    std::string DataForecast{};
    for (size_t i = 1; i < storage_forecast->all_Forecast.size (); ++i) {
        DataForecast.append (storage_forecast->all_Forecast.at (i)->getForecast ());
        // storage_forecast->all_Forecast.at (i).release ();
        // assert (storage_forecast->all_Forecast.at (i) == nullptr);
    }
    wshow_weather2->set_Label_Text_TAF (std::move (DataForecast));
    // очистка буферов
    storage_forecast->all_Forecast.clear ();
    DataForecast.clear ();
    downloader->buff->clear ();
    wshow_weather2->move (10, 0);
    wshow_weather2->show ();
    // запуск таймера
    //  qDebug () << "Start_close_timer" << QTime::currentTime ().toString ();
    //  wshow_weather->start_close_timer ();
}

void Widget::Show_weather ()
{
    qDebug () << "\nposition_selection" << position_selection << "\n";
    switch (position_selection) {
        case 1:
            emit ui->pushButton_UUWW->clicked ();
            wshow_weather2->move (10, 0);
            break;
        case 2:
            emit ui->pushButton_UUDD->clicked ();
            wshow_weather2->move (300, 0);
            break;
        case 3:
            emit ui->pushButton_UUEE->clicked ();
            wshow_weather2->move (600, 0);
            break;
        default:
            break;
    }

    if (position_selection < 3) {
        position_selection++;
    }
    else {
        position_selection = 1;
    }
}

void Widget::Show_Error (const QString& ErrorMsg)
{
    QMessageBox m (QMessageBox::Information, "Ошибка доступа", ErrorMsg, QMessageBox::NoButton, this);
    m.exec ();
}
