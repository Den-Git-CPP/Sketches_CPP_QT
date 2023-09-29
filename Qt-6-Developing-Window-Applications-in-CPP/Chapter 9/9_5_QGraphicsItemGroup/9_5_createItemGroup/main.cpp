#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsItemGroup>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsItemGroup");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 500.0, 335.0);
   scene->setBackgroundBrush(Qt::white);

   QGraphicsLineItem *line1 = scene->addLine(50.0, 50.0, 450.0, 50.0,
                                             QPen(Qt::red, 3));
   line1->setFlag(QGraphicsItem::ItemIsMovable);
   line1->setFlag(QGraphicsItem::ItemIsSelectable);

   QGraphicsLineItem *line2 = scene->addLine(QLineF(50.0, 100.0, 450.0, 100.0),
                                             QPen(Qt::blue, 3));
   line2->setFlag(QGraphicsItem::ItemIsMovable);
   line2->setFlag(QGraphicsItem::ItemIsSelectable);

   QList<QGraphicsItem *> items;
   items << line1 << line2;
   QGraphicsItemGroup *group = scene->createItemGroup(items);
   group->setFlag(QGraphicsItem::ItemIsMovable);
   group->setFlag(QGraphicsItem::ItemIsSelectable);

   QGraphicsRectItem *rect = scene->addRect(QRectF(0.0, 0.0, 400.0, 100.0),
                        QPen(Qt::blue, 3),
                        QBrush(Qt::green));
   rect->setPos(QPointF(50.0, 150.0));
   rect->setFlag(QGraphicsItem::ItemIsMovable);
   rect->setFlag(QGraphicsItem::ItemIsSelectable);

   QGraphicsView *view = new QGraphicsView(scene);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
