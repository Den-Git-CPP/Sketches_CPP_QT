#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsTextItem");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 500.0, 535.0);
   scene->setBackgroundBrush(Qt::white);

   QGraphicsTextItem *item = new QGraphicsTextItem();
   item->setHtml("<u>Форматированный <b>текст</b></u>");
   item->setDefaultTextColor(Qt::darkBlue);
   item->setFont(QFont("Verdana", 16));
   item->setPos(QPointF(10.0, 150.0));
   item->setTextWidth(300);
   item->setTextInteractionFlags(Qt::TextEditorInteraction);
   item->setTabChangesFocus(false);
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
