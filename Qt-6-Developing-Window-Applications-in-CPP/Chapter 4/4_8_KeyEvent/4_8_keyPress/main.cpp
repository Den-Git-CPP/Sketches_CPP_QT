#include "mylabel.h"
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("События клавиатуры");
   window.resize(350, 100);
   MyLabel *label = new MyLabel("Нажмите любую клавишу");
   label->setFrameStyle(QFrame::Box | QFrame::Plain);
   QLineEdit *lineEdit = new QLineEdit();
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   vbox->addWidget(lineEdit);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
/*
- Щелкните мышью на надписи, чтобы установить фокус ввода
- Нажмите любую клавишу
- Нажмите обычную клавишу вместе с модификаторами
- Нажмите комбинацию клавиш <Ctrl>+<C>
- Нажмите клавишу <B>
*/
