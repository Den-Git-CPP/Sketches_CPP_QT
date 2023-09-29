#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QSpinBox>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("setHorizontalSpacing");
   window.resize(400, 150);

   QLineEdit *lineEdit = new QLineEdit();
   QTextEdit *textEdit = new QTextEdit();
   QSpinBox *spinBox = new QSpinBox();
   QPushButton *btn1 = new QPushButton("О&тправить");
   QPushButton *btn2 = new QPushButton("О&чистить");

   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(btn1);
   hbox->addWidget(btn2);
   QFormLayout *form = new QFormLayout();
   form->setHorizontalSpacing(30);
   form->setVerticalSpacing(10);
   form->addRow("&Название:", lineEdit);
   form->addRow("&Описание:", textEdit);
   form->addRow("&Количество:", spinBox);
   form->addRow(hbox);
   window.setLayout(form);

   window.show();
   return app.exec();
}
