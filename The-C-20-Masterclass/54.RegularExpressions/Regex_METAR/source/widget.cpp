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
    connect (ui->pushButton_UUWW, &QPushButton::clicked, downloader, [=, this] () {
        downloader->getData ("UUWW");
        // getBufferFromDowloanderToSForecast ();
    });
    // по окончанию получения данных считываем данные из буфера
    connect (ui->pushButton_UUDD, &QPushButton::clicked, downloader, [=, this] () {
        downloader->getData ("UUDD");
    });
    connect (ui->pushButton_UUEE, &QPushButton::clicked, downloader, [=, this] () {
        downloader->getData ("UUEE");
    });
    connect (downloader, &Downloader::onReady, this, &Widget::getBufferFromDowloanderToSForecast);
    connect (downloader, &Downloader::ErrorDownload, downloader, [=, this] () {
        Show_Error (downloader->ErrorString);
    });

    //  запуск запроса по умолчанию
    timer_show_weather = new QTimer (this);
    timer_show_weather->setInterval (600000); // интервал 10 мин Qtimer 1000 ->1сек
    connect (timer_show_weather, &QTimer::timeout, [=, this] () {
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
    // std::string f_str{
    //     "UUWW 292100Z 24009MPS 9999 OVC005 M02/M03 Q1027 R24/510345 TEMPO 2921/3001 26008G13MPS -FZDZ OVC004 NOSIG\nTAF UUWW 291956Z "
    //     "2921/3021 23005MPS 6000 FEW004 BKN007 TXM00/3012Z TNM03/2921Z \n PROB40 \n TEMPO 2921/3001 26008G13MPS -FZDZ OVC004 \n  TEMPO "
    //     "3001/3021 OVC004 \n  BECMG 3001/3004 29005MPS "
    //     "\n  BECMG 3016/3019 23003MPS\n"
    // };
    // storage_forecast->split_str (std::move (f_str));
    if (downloader->buff->data ()) {
        storage_forecast->split_str (std::move (downloader->buff->data ()));
    }
    // название аэропорта
    wshow_weather2->set_Label_Name_Airport (std::move (std::move (*storage_forecast->all_Forecast.at (0)->Airport)));
    //// название METAR
    std::string DataForecast{};
    wshow_weather2->set_Label_Text_Raw_METAR (std::move (std::move (storage_forecast->RawMETAR)));
    if (storage_forecast->TempoInMetar == 1) {
        for (size_t i = 0; i < 2; ++i) {
            DataForecast.append (storage_forecast->all_Forecast.at (i)->getForecast ());
            storage_forecast->all_Forecast.at (i).release ();
        }
    }
    else {
        DataForecast.append (storage_forecast->all_Forecast.at (0)->getForecast ());
    }
    wshow_weather2->set_Label_Text_METAR (std::move (DataForecast));
    //// название TAF
    wshow_weather2->set_Label_Text_Raw_TAF (std::move (std::move (storage_forecast->RawTAF)));

    for (size_t i = (1 + storage_forecast->TempoInMetar); i < storage_forecast->all_Forecast.size (); ++i) {
        DataForecast.append (storage_forecast->all_Forecast.at (i)->getForecast ());
        storage_forecast->all_Forecast.at (i).release ();
        // assert (storage_forecast->all_Forecast.at (i) == nullptr);
    }
    wshow_weather2->set_Label_Text_TAF (std::move (DataForecast));
    // очистка буферов
    storage_forecast->all_Forecast.clear ();
    DataForecast.clear ();
    downloader->buff->clear ();
    // показ погоды
    wshow_weather2->move (10, 0);
    wshow_weather2->show ();
}

void Widget::Show_weather ()
{
    // qDebug () << "\nposition_selection" << position_selection << "\n";
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
