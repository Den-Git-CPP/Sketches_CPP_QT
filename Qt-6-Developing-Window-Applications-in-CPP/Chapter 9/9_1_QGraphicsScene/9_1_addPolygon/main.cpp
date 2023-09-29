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

   QPolygonF p;
   p << QPointF(50.0, 50.0) << QPointF(450.0, 50.0)
     << QPointF(250.0, 250.0);
   scene->addPolygon(p, QPen(Qt::red, 3), QBrush(Qt::yellow));

   QGraphicsView *view = new QGraphicsView(scene);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
