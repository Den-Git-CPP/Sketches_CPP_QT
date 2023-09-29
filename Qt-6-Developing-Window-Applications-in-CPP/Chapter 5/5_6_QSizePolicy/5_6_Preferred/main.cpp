#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QSizePolicy>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Preferred");
   window.resize(350, 150);

   QLabel *label = new QLabel("Текст надписи");
   QPushButton *btn = new QPushButton("Текст на кнопке");

   QSizePolicy policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
   label->setFrameStyle(QFrame::Box | QFrame::Plain);
   label->setSizePolicy(policy);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   vbox->addWidget(btn);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}

