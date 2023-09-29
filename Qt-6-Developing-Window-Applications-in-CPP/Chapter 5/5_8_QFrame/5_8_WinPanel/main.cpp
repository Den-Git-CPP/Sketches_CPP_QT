#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QFrame. WinPanel");
   window.resize(350, 250);
   QFrame *frame1 = new QFrame();
   QFrame *frame2 = new QFrame();
   QFrame *frame3 = new QFrame();
   frame1->setFrameStyle(QFrame::WinPanel | QFrame::Plain);
   frame2->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
   frame3->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(frame1);
   vbox->addWidget(frame2);
   vbox->addWidget(frame3);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}

