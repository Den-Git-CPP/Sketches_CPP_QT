#pragma once
#include <QWidget>
#include "personmodel.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addPersonButton_clicked();

    void on_removePersonButton_clicked();

private:
    Ui::Widget *ui;
     PersonModel * model;
};


