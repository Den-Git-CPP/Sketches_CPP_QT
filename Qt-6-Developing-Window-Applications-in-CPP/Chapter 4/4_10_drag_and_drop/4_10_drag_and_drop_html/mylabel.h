#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QString>
#include <QPointF>
#include <QMouseEvent>
#include <QApplication>
#include <QMimeData>
#include <QDrag>

class MyLabel : public QLabel
{
   Q_OBJECT
protected:
   void mousePressEvent(QMouseEvent *e) override;
   void mouseMoveEvent(QMouseEvent *e) override;
private slots:
   void on_action_changed(Qt::DropAction);
   void on_target_changed(QObject *);
public:
   MyLabel(const QString &text, QWidget *parent=nullptr);
   QPointF startPos;
};

#endif // MYLABEL_H
