#include "mywidget.h"
#include "./ui_mywidget.h"

MyWidget::MyWidget (QWidget* parent) : QWidget (parent), ui (new Ui::MyWidget)
{
    ui->setupUi (this);
    m_timer = new QTimer (this);
    connect (m_timer, &QTimer::timeout, this, &MyWidget::close);
}

MyWidget::~MyWidget ()
{
    delete ui;
}

void MyWidget::closeEvent (QCloseEvent* event)
{
    m_timer->start (1000); // Delay closing for 1 second
    event->accept ();
}

void MyWidget::close ()
{
    // Your closing logic
    QWidget::close ();
}
