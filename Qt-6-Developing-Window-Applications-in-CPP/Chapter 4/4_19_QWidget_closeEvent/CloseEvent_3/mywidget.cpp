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
    // Perform custom cleanup tasks
    cleanupResources ();
    QWidget::closeEvent (event);

    // ========= OR============
    /*
       // Prevent accidental closure
        if (isClosingAllowed()) {
            event->accept();
        } else {
            event->ignore();
        }
    */
}

void MyWidget::cleanupResources ()
{
    // Your cleanup logic
}

bool isClosingAllowed ()
{
    // Your logic to determine if closing is allowed
    return false;
}
