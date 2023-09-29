#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsScene");
   window.resize(500, 300);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 475.0, 275.0);
   scene->setBackgroundBrush(Qt::white);

   QGraphicsRectItem *rect1 = scene->addRect(0.0, 0.0, 400.0, 100.0,
                 QPen(Qt::red, 3),
                 QBrush(Qt::yellow));
   rect1->setPos(QPointF(50.0, 30.0));
   QGraphicsRectItem *rect2 = scene->addRect(QRectF(0.0, 0.0, 400.0, 100.0),
                 QPen(Qt::blue, 3),
                 QBrush(Qt::green));
   rect2->setPos(QPointF(50.0, 150.0));

   QGraphicsView *view = new QGraphicsView(scene);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
