#pragma once

#include <QWidget>

#include <QIcon>
#include <QPalette>
#include <QColor>

#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QStyle>
#include <QPushButton>


class ConvertCoordinat : public QWidget
{
    Q_OBJECT

public:
    ConvertCoordinat(QWidget *parent = nullptr);
    ~ConvertCoordinat();
private slots:
    void ProvCoordinat();
    void Calculate(const QString &str);


private:
    QIcon *icon=nullptr;
    QFont *ft=nullptr;
    QPalette *pa=nullptr;
    QVBoxLayout *vbox=nullptr;
    QLineEdit *lnEdit_in_coord =nullptr;
    QLabel *label_in=nullptr, *label_Long=nullptr, *label_Lat=nullptr,*label_prim=nullptr,*label_att=nullptr;//
    QPushButton *bt_res= nullptr;
    int Degree_Long{0},Degree_Lat{0};
    int Minutes_Long{0},Minutes_Lat{0};
    double  Seconds_Long{0.0},Seconds_Lat{0.0};
};
