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

void MyWidget::closeEvent (QCloseEvent* event)
{
    // Prompt the user for confirmation
    if (QMessageBox::question (this, "Confirm Exit", "Are you sure you want to quit?") == QMessageBox::Yes) {
        QWidget::closeEvent (event);
    }
    else {
        event->ignore ();
    }
}
