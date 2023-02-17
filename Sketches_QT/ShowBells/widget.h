#pragma once

#include <QWidget>
#include <QLabel>
#include <QPalette>
#include <QColor>
#include <QIcon>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QDebug>

#include "lb_bells.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QLabel *label=nullptr;
    QVBoxLayout *vbox=nullptr;

    QFont *ft=nullptr;
    QPalette *pa=nullptr;
    QIcon *icon=nullptr;

    lb_bells *bells=nullptr;
    QTimer* timer_show_bells =nullptr;
    QTimer* timer_close_bells =nullptr;

    void Show_Bells();
};
