#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QLabel");
   window.resize(350, 70);

   QLabel *label = new QLabel();
   label->setFrameStyle(QFrame::Box | QFrame::Plain);
   label->setPixmap(QPixmap("G:\\ProjectQT\\CH06\\6_1_QLabel\\6_1_setScaledContents\\photo.jpg"));
   label->setAutoFillBackground(true);
   label->setScaledContents(true);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
