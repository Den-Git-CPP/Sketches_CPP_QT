#include "firstform.h"
#include "./ui_firstform.h"

FirstForm::FirstForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstForm)
{
    ui->setupUi(this);
    // Connecting the textbox's returnPressed() signal so that
    // we can react to it
   connect(ui->myTextEdit, SIGNAL(returnPressed),
           this, SIGNAL(onTextBoxReturnPressed()));
}


FirstForm::~FirstForm()
{
    delete ui;
}

void FirstForm::onTextBoxReturnPressed()
{
    // Emitting a signal with the new text
   emit this->newTextEntered(ui->myTextEdit->text());
}


void FirstForm::on_pushButton_clicked()
{
    onTextBoxReturnPressed();
}


void FirstForm::on_pushButton_2_clicked()
{

}

