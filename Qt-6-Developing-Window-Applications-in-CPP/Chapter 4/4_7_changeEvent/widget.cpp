#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Полноэкранный режим");
   btn2 = new QPushButton("Нормальный режим");
   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   setLayout(vbox);
   QObject::connect(btn1, SIGNAL(clicked()),
                    this, SLOT(showFullScreen()));
   QObject::connect(btn2, SIGNAL(clicked()),
                    this, SLOT(showNormal()));
}

void Widget::changeEvent(QEvent *e)
{
   if (e->type() == QEvent::WindowStateChange) {
      if (isMinimized()) {
         qDebug() << "Окно свернуто";
      }
      else if (isMaximized()) {
         qDebug() << "Окно раскрыто до максимальных размеров";
      }
      else if (isFullScreen()) {
         qDebug() << "Полноэкранный режим";
      }
      else if (isActiveWindow()) {
         qDebug() << "Окно находится в фокусе ввода";
      }
   }
   QWidget::changeEvent(e); // Отправляем дальше
}

void Widget::showEvent(QShowEvent *e)
{
   qDebug() << "Окно отображено";
   QWidget::showEvent(e); // Отправляем дальше
}

void Widget::hideEvent(QHideEvent *e)
{
   qDebug() << "Окно скрыто";
   QWidget::hideEvent(e); // Отправляем дальше
}

Widget::~Widget() {}

