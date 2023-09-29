#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsPixmapItem");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 500.0, 535.0);
   scene->setBackgroundBrush(Qt::white);

   QPixmap pix("G:\\ProjectQT\\Chapter 9\\9_4_Item\\9_4_6_QGraphicsPixmapItem\\9_4_6_setShapeMode\\photo.jpg");
   QBitmap mask(pix.size());
   mask.clear();
   QPainter painter;
   painter.begin(&mask);
   painter.setPen(Qt::color1);
   painter.setBrush(Qt::color1);
   painter.setRenderHint(QPainter::Antialiasing);
   painter.drawEllipse(50, 50, 400, 250);
   painter.end();
   pix.setMask(mask);

   QGraphicsPixmapItem *item = new QGraphicsPixmapItem();
   item->setPixmap(pix);
   item->setOffset(50, 50);
   item->setShapeMode(QGraphicsPixmapItem::MaskShape);
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
