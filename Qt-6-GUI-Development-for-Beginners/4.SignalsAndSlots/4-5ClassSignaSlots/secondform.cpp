#include "secondform.h"
#include "ui_secondform.h"

SecondForm::SecondForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondForm)
{
    ui->setupUi(this);
}

SecondForm::~SecondForm()
{
    delete ui;
}

void SecondForm::onNewTextEntered(const QString &text)
{
    // Adding a new item to the list widget
    ui->myListWidget->addItem(text);
}
