#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent)
   : QDialog(parent)
{
   setWindowTitle("Диалоговое окно");
   resize(200, 70);

   mainBox = new QVBoxLayout();

   lineEdit = new QLineEdit();
   mainBox->addWidget(lineEdit);

   hbox = new QHBoxLayout();
   btnOK = new QPushButton("&OK");
   btnCancel = new QPushButton("&Cancel");
   btnCancel->setDefault(true);
   connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
   connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
   hbox->addWidget(btnOK);
   hbox->addWidget(btnCancel);
   mainBox->addLayout(hbox);

   setLayout(mainBox);

   setSizeGripEnabled(true);
}
