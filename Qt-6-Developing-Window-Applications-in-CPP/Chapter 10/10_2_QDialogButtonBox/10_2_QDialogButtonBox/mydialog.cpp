#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent)
   : QDialog(parent)
{
   setWindowTitle("Диалоговое окно");
   resize(200, 70);

   mainBox = new QVBoxLayout();

   lineEdit = new QLineEdit();
   mainBox->addWidget(lineEdit);

   box = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
            Qt::Horizontal);
   connect(box, SIGNAL(accepted()), this, SLOT(accept()));
   connect(box, SIGNAL(rejected()), this, SLOT(reject()));
   mainBox->addWidget(box);

   setLayout(mainBox);
}
