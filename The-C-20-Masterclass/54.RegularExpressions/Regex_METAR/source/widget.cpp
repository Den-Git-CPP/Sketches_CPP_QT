#include "include/widget.h"
#include "source/ui_widget.h"

#include <QPoint>
#include <QScreen>

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
    // timer_close_weather = new QTimer (this);
    //timer_close_weather->setInterval (12000); // Qtimer 1000 ->1сек
    // timer_close_weather->setSingleShot (true);
    // connect (timer_close_weather, &QTimer::timeout, [=] {
    //     qDebug () << "Close weather" << QTime::currentTime ().toString ();
    //     wshow_weather->close ();
    // });

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
    timer_show_weather->setInterval (60000); // интервал 1 мин Qtimer 1000 ->1сек
    connect (timer_show_weather, &QTimer::timeout, this, [=] () {
        Show_weather ();
    });
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
    // название аэропорта
    wshow_weather->label_name_airport->setText (QString::fromStdString (*storage_forecast->all_Forecast.at (0)->Airport));
    // название METAR
    wshow_weather->label_text_raw_METAR->setText (QString::fromStdString (storage_forecast->RawMETAR));
    wshow_weather->label_text_METAR->setText (QString::fromStdString (storage_forecast->all_Forecast.at (0)->getForecast ()));
    // название TAF
    wshow_weather->label_text_raw_TAF->setText (QString::fromStdString (storage_forecast->RawTAF));

    std::string DataForecast{};
    for (size_t i = 1; i < storage_forecast->all_Forecast.size (); ++i) {
        DataForecast.append (storage_forecast->all_Forecast.at (i)->getForecast ());
    }
    wshow_weather->label_text_TAF->setText (QString::fromStdString (DataForecast));
    DataForecast.clear ();
    downloader->buff.clear ();

    wshow_weather->show ();
    // timer_close_weather->start ();
    // qDebug () << "start_close_timer" << QTime::currentTime ().toString ();
}

void Widget::Show_weather ()
{
    switch (position_selection) {
        case 1:
            emit ui->pushButton_UUWW->clicked ();
            wshow_weather->move (10, 0);
            position_selection++;

            break;
        case 2:
            emit ui->pushButton_UUDD->clicked ();
            wshow_weather->move (300, 0);
            position_selection++;
            break;
        case 3:
            emit ui->pushButton_UUEE->clicked ();
            wshow_weather->move (600, 0);
            position_selection = 1;
            break;
    }
}

void Widget::Show_Error (const QString& ErrorMsg)
{

    // QMessageBox::information (QApplication::activeWindow (), "Ошибка доступа", ErrorMsg, QMessageBox::Close);

    QMessageBox m (QMessageBox::Information, "Ошибка доступа", ErrorMsg, QMessageBox::NoButton, this);

    // QScreen* qc = QGuiApplication::primaryScreen ();
    // QPoint cp   = qc->geometry ().center ();
    // m.move (cp);
    //    m.move (center.x () - width () * 0.5, center.y () - height () * 0.5);
    m.exec ();
}
