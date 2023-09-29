#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsSimpleTextItem");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 500.0, 535.0);
   scene->setBackgroundBrush(Qt::white);

   QGraphicsSimpleTextItem *item = new QGraphicsSimpleTextItem();
   item->setText("Простой текст");
   item->setPen(QPen(Qt::darkBlue, 3));
   item->setFont(QFont("Verdana", 25));
   item->setPos(QPointF(50.0, 150.0));
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
