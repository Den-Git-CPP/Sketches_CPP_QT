#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QFocusEvent>
#include <QKeyEvent>
#include <QString>
#include <QStringList>

class MyLabel : public QLabel
{
   Q_OBJECT
protected:
   void focusInEvent(QFocusEvent *e) override;
   void focusOutEvent(QFocusEvent *e) override;
   void keyPressEvent(QKeyEvent *e) override;
   void keyReleaseEvent(QKeyEvent *e) override;
public:
   MyLabel(const QString &text, QWidget *parent=nullptr);
};

#endif // MYLABEL_H
