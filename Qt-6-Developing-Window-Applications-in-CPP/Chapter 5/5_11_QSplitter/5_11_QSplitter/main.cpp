#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSplitter>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Класс QSplitter");
   window.resize(400, 250);
   QSplitter *splitter = new QSplitter(Qt::Vertical);
   QSplitter *splitter2 = new QSplitter(Qt::Horizontal);
   QLabel *label1 = new QLabel("Содержимое 1");
   QLabel *label2 = new QLabel("Содержимое 2");
   QLabel *label3 = new QLabel("Содержимое 3");
   label1->setFrameStyle(QFrame::Box | QFrame::Plain);
   label2->setFrameStyle(QFrame::Box | QFrame::Plain);
   label3->setFrameStyle(QFrame::Box | QFrame::Plain);
   splitter2->addWidget(label1);
   splitter2->addWidget(label2);
   splitter->addWidget(splitter2);
   splitter->addWidget(label3);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(splitter);
   window.setLayout(vbox);
   window.show();

   return app.exec();
}
