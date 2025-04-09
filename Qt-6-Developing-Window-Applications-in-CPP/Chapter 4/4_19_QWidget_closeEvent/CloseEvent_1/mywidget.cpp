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
    //or
    /*
    switch (QMessageBox::information (this, tr ("Подскажите"), //
      tr ("Вы уверены, что хотите выйти из программы?"),       //
      tr ("OK"), tr ("Отменить"),                              //
      0, 1)) {
        case 0:
            event->accept ();
            break;
        case 1:
        default:
            event->ignore ();
            break;
    }    
    */

}
