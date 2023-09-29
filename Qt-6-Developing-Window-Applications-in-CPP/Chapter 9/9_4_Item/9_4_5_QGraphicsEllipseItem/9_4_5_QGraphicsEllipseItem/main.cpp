#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsEllipseItem");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 500.0, 535.0);
   scene->setBackgroundBrush(Qt::white);

   QGraphicsEllipseItem *item = new QGraphicsEllipseItem(0.0, 0.0, 400.0, 400.0);
   item->setPos(QPointF(50.0, 50.0));
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
