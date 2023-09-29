#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QCommandLinkButton>

void on_clicked() {
   qDebug() << "Кнопка нажата";
}

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QCommandLinkButton");
   window.resize(350, 100);

   QCommandLinkButton *button = new QCommandLinkButton(
                                     "Текст на кнопке");
   button->setDescription("Дополнительный текст");
   QObject::connect(button, &QPushButton::clicked, on_clicked);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(button);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
