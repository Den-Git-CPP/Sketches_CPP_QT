#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLabel>
#include <QIcon>
#include <QStyle>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTabWidget");
   window.resize(350, 120);
   QTabWidget *tab = new QTabWidget();
   QIcon icon1 = window.style()->standardIcon(QStyle::SP_DriveHDIcon);
   QIcon icon2 = window.style()->standardIcon(QStyle::SP_DriveCDIcon);
   QIcon icon3("G:\\ProjectQT\\CH05\\5_9_QTabWidget\\5_9_icon\\test.ico");
   tab->addTab(new QLabel("Содержимое вкладки 1"), icon1, "Вкладка &1");
   tab->addTab(new QLabel("Содержимое вкладки 2"), icon2, "Вкладка &2");
   tab->addTab(new QLabel("Содержимое вкладки 3"), icon3, "Вкладка &3");
   tab->setCurrentIndex(0);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(tab);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}

