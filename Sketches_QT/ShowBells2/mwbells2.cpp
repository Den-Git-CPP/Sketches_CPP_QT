#include "mwbells2.h"
#include "./ui_mwbells2.h"

mwBells2::mwBells2 (QWidget* parent) : QMainWindow (parent), ui (new Ui::mwBells2)
{
    ui->setupUi (this);
    this->setWindowFlags (Qt::WindowCloseButtonHint);

    bells = new n_bells ();
}

mwBells2::~mwBells2 ()
{
    killTimer (timer_id);
}

void mwBells2::timerEvent (QTimerEvent* event)
{
    // QTime t = QTime::currentTime ();
    // qDebug () << "ID =" << event->timerId () << " " << t.toString ("HH:mm:ss");
    bells->move (this->mapToGlobal (QPoint (-20, -50)));
    bells->show ();
}

void mwBells2::showEvent (QShowEvent* event)
{
    // IMPORTANT: Always call the base class implementation first!
    // mwBells2::showEvent (event);
    // Your custom code here
    timer_id = startTimer (5000); // 15 секунд
}
