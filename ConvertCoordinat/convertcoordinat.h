#pragma once

#include <QWidget>

#include <QIcon>
#include <QPalette>
#include <QColor>

#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class ConvertCoordinat : public QWidget
{
    Q_OBJECT

public:
    ConvertCoordinat(QWidget *parent = nullptr);
    ~ConvertCoordinat();
private slots:
    void ProvCoordinat();
private:
    QIcon *icon=nullptr;
    QFont *ft=nullptr;
    QPalette *pa=nullptr;
    QVBoxLayout *vbox=nullptr;
    QLineEdit *lnEdit_in_coord =nullptr;
    QLabel *label_in=nullptr, *label_dol=nullptr, *label_shir=nullptr,*label_prim=nullptr;//
    QPushButton *bt_res= nullptr;


};
