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
    if (isDataModified ()) {
        int ret = QMessageBox::question (this, "Save Changes", "Do you want to save your changes?", QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        switch (ret) {
            case QMessageBox::Save:
                if (!saveData ()) {
                    event->ignore ();
                }
                break;
            case QMessageBox::Cancel:
                event->ignore ();
                break;
            default:
                break;
        }
    }
    else {
        event->accept ();
    }
}

bool MyWidget::isDataModified ()
{
    // Your logic to check if data has been modified
    qDebug () << __func__;
    return false;
}

bool MyWidget::saveData ()
{
    // Your logic to save data
    qDebug () << __func__;
    return true;
}
