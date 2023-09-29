#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include <QStringList>

class MyLabel : public QLabel
{
   Q_OBJECT
protected:
   void mouseMoveEvent(QMouseEvent *e) override;
public:
   MyLabel(const QString &text, QWidget *parent=nullptr);
};

#endif // MYLABEL_H
