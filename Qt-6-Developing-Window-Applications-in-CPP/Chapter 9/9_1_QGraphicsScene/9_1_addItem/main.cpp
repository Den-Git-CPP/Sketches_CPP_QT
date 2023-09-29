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

   QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(
                                       0.0, 0.0, 300.0, 100.0);
   ellipse->setPen(QPen(Qt::red, 3));
   ellipse->setBrush(QBrush(Qt::yellow));
   ellipse->setPos(QPointF(50.0, 50.0));
   scene->addItem(ellipse);

   QGraphicsView *view = new QGraphicsView(scene);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
