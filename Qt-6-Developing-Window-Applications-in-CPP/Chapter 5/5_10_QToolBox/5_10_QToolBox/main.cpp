#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QToolBox>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Класс QToolBox");
   window.resize(350, 150);
   QToolBox *toolBox = new QToolBox();
   toolBox->addItem(new QLabel("Содержимое вкладки 1"), "Вкладка &1");
   toolBox->addItem(new QLabel("Содержимое вкладки 2"), "Вкладка &2");
   toolBox->addItem(new QLabel("Содержимое вкладки 3"), "Вкладка &3");
   toolBox->setCurrentIndex(0);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(toolBox);
   window.setLayout(vbox);
   window.show();

   return app.exec();
}
