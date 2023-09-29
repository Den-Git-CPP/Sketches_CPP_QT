#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsScene");
   window.resize(500, 300);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 475.0, 275.0);
   scene->setBackgroundBrush(Qt::white);

   QGraphicsEllipseItem *e1 = scene->addEllipse(0.0, 0.0, 400.0, 100.0,
                 QPen(Qt::red, 3),
                 QBrush(Qt::yellow));
   e1->setPos(QPointF(50.0, 30.0));
   QGraphicsEllipseItem *e2 = scene->addEllipse(QRectF(0.0, 0.0, 400.0, 100.0),
                 QPen(Qt::blue, 3),
                 QBrush(Qt::green));
   e2->setPos(QPointF(50.0, 150.0));

   QGraphicsView *view = new QGraphicsView(scene);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
