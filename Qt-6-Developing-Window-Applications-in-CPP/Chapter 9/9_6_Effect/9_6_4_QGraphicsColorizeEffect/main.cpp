#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsColorizeEffect>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsColorizeEffect");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 500.0, 335.0);
   scene->setBackgroundBrush(Qt::white);

   QGraphicsRectItem *rect = scene->addRect(QRectF(0.0, 0.0, 400.0, 100.0),
                        QPen(Qt::blue, 3),
                        QBrush(Qt::green));
   rect->setPos(QPointF(50.0, 150.0));
   rect->setFlag(QGraphicsItem::ItemIsMovable);
   rect->setFlag(QGraphicsItem::ItemIsSelectable);

   QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect(&window);
   effect->setColor(QColor(255, 0, 0, 255));
   effect->setStrength(0.5);
   rect->setGraphicsEffect(effect);

   QGraphicsView *view = new QGraphicsView(scene);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
