#include "widget.h"
#include <QStyle>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QMessageBox");
   window.resize(300, 70);
   QIcon ico = window.style()->standardIcon(QStyle::SP_MessageBoxCritical);
   app.setWindowIcon(ico);

   window.show();
   return app.exec();
}
