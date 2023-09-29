#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(300, 300);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   //painter.setRenderHint(QPainter::Antialiasing);
   painter.setPen(QPen(Qt::black));
   painter.setBrush(QBrush(Qt::white));
   painter.drawRect(3, 3, 294, 294);

   painter.setRenderHint(QPainter::TextAntialiasing);
   painter.setPen(QPen(Qt::red, 1));
   painter.setFont(QFont("Tahoma", 12));
   painter.drawText(20, 30, "Строка 1");
   painter.drawText(QPoint(150, 30), "Строка 2");

   painter.drawRect(QRect(20, 40, 210, 50));
   painter.drawText(20, 40, 210, 50,
                    Qt::TextDontClip,
                    "Строка 3 текст будет выходить за границы");

   painter.drawRect(QRect(20, 100, 260, 30));
   painter.drawText(20, 100, 260, 30,
                    Qt::AlignCenter | Qt::TextShowMnemonic,
                    "Строка &4");

   painter.drawRect(QRect(20, 140, 260, 50));
   painter.drawText(QRect(20, 140, 260, 50),
                    Qt::AlignRight | Qt::TextSingleLine,
                    "Строка 5\nвсе специальные символы трактуются как пробелы и текст выводится в одну строку");

   painter.drawRect(QRect(20, 190, 260, 50));
   painter.drawText(QRect(20, 190, 260, 50),
                    Qt::AlignRight | Qt::TextWordWrap,
                    "Строка 6 очень длинный текст на двух строках");

   painter.drawRect(QRect(20, 240, 260, 50));
   painter.drawText(QRect(20, 240, 260, 50),
                    Qt::AlignRight | Qt::TextWrapAnywhere,
                    "Строка7оченьдлинныйтекстнадвухстроках");

}
