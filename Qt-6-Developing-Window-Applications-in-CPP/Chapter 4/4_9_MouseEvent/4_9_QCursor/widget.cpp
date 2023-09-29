#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   QPixmap pix("G:\\ProjectQT\\CH04\\4_9_MouseEvent\\4_9_QCursor\\cursor.png");
   setCursor(QCursor(pix, 0, 0));
   label = new QLabel("Щелкните мышью в окне");
   label->setAlignment(Qt::AlignCenter);
   vbox = new QVBoxLayout();
   vbox->addWidget(label);
   setLayout(vbox);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
   QString s = QString("X: %1, Y: %2")
                  .arg(e->position().x()).arg(e->position().y());
   label->setText(s);
   QWidget::mousePressEvent(e);
}

Widget::~Widget() {}
