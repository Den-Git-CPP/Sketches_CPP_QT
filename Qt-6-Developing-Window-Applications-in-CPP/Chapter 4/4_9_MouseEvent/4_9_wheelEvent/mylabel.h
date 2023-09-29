#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QWheelEvent>
#include <QString>

class MyLabel : public QLabel
{
   Q_OBJECT
protected:
   void wheelEvent(QWheelEvent *e) override;
public:
   MyLabel(const QString &text, QWidget *parent=nullptr);
};

#endif // MYLABEL_H
