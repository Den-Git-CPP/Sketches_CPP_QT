#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QToolBox>
#include <QStyle>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Класс QToolBox");
   window.resize(350, 150);
   QToolBox *toolBox = new QToolBox();
   QIcon icon1 = window.style()->standardIcon(QStyle::SP_DriveHDIcon);
   QIcon icon2 = window.style()->standardIcon(QStyle::SP_DriveCDIcon);
   QIcon icon3("C:\\cpp\\projectsQt\\Test\\test.ico");
   toolBox->addItem(new QLabel("Содержимое вкладки 1"), icon1, "Вкладка &1");
   toolBox->addItem(new QLabel("Содержимое вкладки 2"), icon2, "Вкладка &2");
   toolBox->addItem(new QLabel("Содержимое вкладки 3"), icon3, "Вкладка &3");
   toolBox->setCurrentIndex(0);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(toolBox);
   window.setLayout(vbox);
   window.show();

   return app.exec();
}
