#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLabel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTabWidget");
   window.resize(350, 120);
   QTabWidget *tab = new QTabWidget();
   tab->addTab(new QLabel("Содержимое вкладки 1"), "Вкладка &1");
   tab->addTab(new QLabel("Содержимое вкладки 2"), "Вкладка &2");
   tab->addTab(new QLabel("Содержимое вкладки 3"), "Вкладка &3");
   tab->setCurrentIndex(0);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(tab);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}

