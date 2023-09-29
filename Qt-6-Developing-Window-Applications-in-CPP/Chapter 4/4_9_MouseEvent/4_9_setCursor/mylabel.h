#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QString>

class MyLabel : public QLabel
{
   Q_OBJECT
public:
   MyLabel(const QString &text, QWidget *parent=nullptr);
};

#endif // MYLABEL_H
