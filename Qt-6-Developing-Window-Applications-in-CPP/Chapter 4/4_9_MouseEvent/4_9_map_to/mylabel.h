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
   void mousePressEvent(QMouseEvent *e) override;
public:
   MyLabel(const QString &text, QWidget *parent=nullptr);
private:
   QWidget *prnt;
};

#endif // MYLABEL_H
