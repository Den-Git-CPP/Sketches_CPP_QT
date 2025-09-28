#include "n_bells.h"
#include "ui_n_bells.h"

n_bells::n_bells (QWidget* parent) : QWidget (parent), ui (new Ui::n_bells)
{
    ui->setupUi (this);
    this->setWindowFlags (Qt::WindowCloseButtonHint);
}

n_bells::~n_bells ()
{
    delete ui;
}

void n_bells::timerEvent (QTimerEvent* event)
{
    // QTime t = QTime::currentTime ();
    // qDebug () << "ID close =" << timer_close << " " << t.toString ("HH:mm:ss");
    killTimer (timer_close);
    this->close ();
}

void n_bells::showEvent (QShowEvent* event)
{
    timer_close = startTimer (2000);
    // QTime t     = QTime::currentTime ();
    // qDebug () << "ID start =" << timer_close << " " << t.toString ("HH:mm:ss");
}

// void n_bells::closeEvent (QCloseEvent* event)
//{
//    // QTime t = QTime::currentTime ();
//    // qDebug () << "ID close =" << timer_close << " " << t.toString ("HH:mm:ss");
//    // killTimer (timer_close);
//}
