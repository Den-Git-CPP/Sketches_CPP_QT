#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsView");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 1500.0, 1335.0);
   scene->setBackgroundBrush(Qt::white);

   QGraphicsLineItem *line1 = scene->addLine(50.0, 50.0, 450.0, 50.0,
                                             QPen(Qt::red, 3));
   line1->setFlag(QGraphicsItem::ItemIsMovable);
   line1->setFlag(QGraphicsItem::ItemIsSelectable);
   line1->setFlag(QGraphicsItem::ItemIsFocusable);

   QGraphicsLineItem *line2 = scene->addLine(QLineF(50.0, 100.0, 450.0, 100.0),
                                             QPen(Qt::blue, 3));
   line2->setFlag(QGraphicsItem::ItemIsMovable);
   line2->setFlag(QGraphicsItem::ItemIsSelectable);
   line2->setFlag(QGraphicsItem::ItemIsFocusable);

   QGraphicsRectItem *rect = scene->addRect(QRectF(0.0, 0.0, 400.0, 100.0),
                        QPen(Qt::blue, 3),
                        QBrush(Qt::green));
   rect->setPos(QPointF(50.0, 150.0));
   rect->setFlag(QGraphicsItem::ItemIsMovable);
   rect->setFlag(QGraphicsItem::ItemIsSelectable);
   rect->setFlag(QGraphicsItem::ItemIsFocusable);

   line1->setSelected(true);

   QGraphicsView *view = new QGraphicsView(scene);

   QPushButton *btn1 = new QPushButton("Показать элемент");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      view->ensureVisible(rect, 100, 100);
   });

   window.show();
   return app.exec();
}
