#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGraphicsScene");
   window.resize(600, 400);

   QGraphicsScene *scene = new QGraphicsScene(0.0, 0.0, 500.0, 335.0);
   scene->setBackgroundBrush(Qt::white);

   QGraphicsPixmapItem *img = scene->addPixmap(
            QPixmap("G:\\Qt-6-Developing-Window-Applications-in-CPP\\Chapter 9\\9_1_QGraphicsScene\\9_1_addPixmap\\photo.jpg"));
   img->setPos(QPointF(10.0, 10.0));

   QGraphicsView *view = new QGraphicsView(scene);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
