#pragma once
#include <QLineEdit>
#include <QCompleter>
#include <QStringList>

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

