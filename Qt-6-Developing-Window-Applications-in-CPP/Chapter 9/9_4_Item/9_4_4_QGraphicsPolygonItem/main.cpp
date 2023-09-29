#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QGraphicsView>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsPolygonItem");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 500.0, 535.0);
   scene->setBackgroundBrush(Qt::white);

   QPolygonF polygon;
   polygon << QPointF(50.0, 50.0) << QPointF(450.0, 50.0)
           << QPointF(250.0, 250.0);
   QGraphicsPolygonItem *item = new QGraphicsPolygonItem(polygon);
   item->setPos(QPointF(10.0, 150.0));
   item->setPen(QPen(Qt::darkBlue, 3));
   item->setBrush(QBrush(Qt::darkGreen));
   item->setFlag(QGraphicsItem::ItemIsMovable);
   item->setFlag(QGraphicsItem::ItemIsSelectable);
   item->setFlag(QGraphicsItem::ItemIsFocusable);
   scene->addItem(item);

   QGraphicsView *view = new QGraphicsView(scene);

   QPushButton *btn1 = new QPushButton("Установить фокус");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      view->setFocus();
   });

   window.show();
   return app.exec();
}
