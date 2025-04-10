#include "mywidget.h"
#include "./ui_mywidget.h"

MyWidget::MyWidget (QWidget* parent) : QWidget (parent), ui (new Ui::MyWidget)
{
    ui->setupUi (this);
    m_timer = new QTimer (this);
    connect (m_timer, &QTimer::timeout, this, &MyWidget::update);
}

MyWidget::~MyWidget ()
{
    delete ui;
}

void MyWidget::showEvent (QShowEvent* event)
{
    m_timer->start (1000);
    QWidget::showEvent (event);
}

void MyWidget::update ()
{
    // Update Data
}
