#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent)
   : QDialog(parent)
{
   setWindowTitle("Диалоговое окно");
   resize(200, 70);

   mainBox = new QVBoxLayout();

   lineEdit = new QLineEdit();
   mainBox->addWidget(lineEdit);

   box = new QDialogButtonBox();
   box->setOrientation(Qt::Horizontal);
   box->setCenterButtons(true);
   box->setStandardButtons(QDialogButtonBox::Ok |
                           QDialogButtonBox::Cancel);
   connect(box, SIGNAL(accepted()), this, SLOT(accept()));
   connect(box, SIGNAL(rejected()), this, SLOT(reject()));
   mainBox->addWidget(box);

   setLayout(mainBox);
}
