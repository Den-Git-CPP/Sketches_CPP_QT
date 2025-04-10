#include "mywidget.h"
#include "./ui_mywidget.h"

MyWidget::MyWidget (QWidget* parent) : QWidget (parent), ui (new Ui::MyWidget)
{
    ui->setupUi (this);
}

MyWidget::~MyWidget ()
{
    delete ui;
}

void MyWidget::showEvent (QShowEvent* event)
{ // Load data from a file when the widget becomes visible
    QFile file ("data.txt");
    if (file.open (QIODevice::ReadOnly)) {
        // Process the file contents
        qDebug () << file.readAll ();
        file.close ();
    }
    qDebug () << "Widget is now visible!";
    QWidget::showEvent (event); // Call the base class implementation
}
