#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QPushButton>


int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsScene");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 500.0, 335.0);
   scene->setBackgroundBrush(Qt::white);

   QWidget *w = new QWidget();
   w->move(50, 50);
   w->resize(300, 50);
   QPushButton *btn = new QPushButton("Командная кнопка");
   QVBoxLayout *b = new QVBoxLayout();
   b->addWidget(btn);
   w->setLayout(b);
   QGraphicsProxyWidget *widget1 = scene->addWidget(w, Qt::Window);
   widget1->setWindowTitle("Заголовок окна 1");

   QWidget *w2 = new QWidget();
   w2->move(50, 250);
   w2->resize(300, 50);
   QGraphicsProxyWidget *widget2 = scene->addWidget(w2, Qt::Window);
   widget2->setWindowTitle("Заголовок окна 2");

   QGraphicsView *view = new QGraphicsView(scene);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   window.setLayout(vbox);

   window.show();
   scene->setActiveWindow(widget2);
   return app.exec();
}
