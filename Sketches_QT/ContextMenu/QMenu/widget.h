#pragma once

#include <QWidget>
#include <QMenu>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
   explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
  void customContextMenuShow(const QPoint& pos);

private:
    Ui::Widget *ui;
};

