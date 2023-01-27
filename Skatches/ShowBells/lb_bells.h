#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QIcon>

class lb_bells : public QWidget
{
    Q_OBJECT
public:
    explicit lb_bells(QWidget *parent = nullptr);

signals:
private:
    QIcon *icon=nullptr;
};

