#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QEnterEvent>
#include <QString>

class MyLabel : public QLabel
{
   Q_OBJECT
protected:
   void enterEvent(QEnterEvent *e) override;
   void leaveEvent(QEvent *e) override;
public:
   MyLabel(const QString &text, QWidget *parent=nullptr);
};

#endif // MYLABEL_H
