#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QScrollArea scrollArea;
   scrollArea.setWindowTitle("Класс QScrollArea");
   scrollArea.resize(300, 200);
   QWidget *widget = new QWidget();
   QLabel *label1 = new QLabel("Содержимое 1");
   QLabel *label2 = new QLabel("Содержимое 2");
   label1->setFrameStyle(QFrame::Box | QFrame::Plain);
   label2->setFrameStyle(QFrame::Box | QFrame::Plain);
   label1->setMinimumSize(350, 150);
   label2->setMinimumHeight(80);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label1);
   vbox->addWidget(label2);
   widget->setLayout(vbox);
   scrollArea.setWidget(widget);
   scrollArea.show();

   return app.exec();
}
