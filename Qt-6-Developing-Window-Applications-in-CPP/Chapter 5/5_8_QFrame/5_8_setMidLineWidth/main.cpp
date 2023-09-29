#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QFrame. setMidLineWidth");
   window.resize(350, 250);
   QFrame *frame1 = new QFrame();
   QFrame *frame2 = new QFrame();
   QFrame *frame3 = new QFrame();
   frame1->setFrameStyle(QFrame::Box | QFrame::Plain);
   frame2->setFrameStyle(QFrame::Box | QFrame::Raised);
   frame3->setFrameStyle(QFrame::Box | QFrame::Sunken);
   frame1->setLineWidth(5);
   frame2->setLineWidth(5);
   frame3->setLineWidth(5);
   frame1->setMidLineWidth(10);
   frame2->setMidLineWidth(10);
   frame3->setMidLineWidth(10);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(frame1);
   vbox->addWidget(frame2);
   vbox->addWidget(frame3);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}

