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
#include <QDebug>
#include <string>

class ConvertCoordinat : public QWidget
{
    Q_OBJECT

public:
    ConvertCoordinat(QWidget *parent = nullptr);
    ~ConvertCoordinat();
private slots:
    void Calculate(const QString &str);
    QString YandexMap(int Degree_Long, int Minutes_Long, double Seconds_Long,
                      int Degree_Lat, int Minutes_Lat, double Seconds_Lat);



private:
    QIcon *icon=nullptr;
    QFont *ft=nullptr;
    QPalette *pa=nullptr;
    QVBoxLayout *vbox=nullptr;
    QLineEdit *lnEdit_in_coord =nullptr;
    QLabel *label_in=nullptr, *label_GEO=nullptr, *label_GEO_map=nullptr;//
    QPushButton *bt_res= nullptr;
    int Degree_Long{0},Degree_Lat{0};
    int Minutes_Long{0},Minutes_Lat{0};
    double  Seconds_Long{0.0},Seconds_Lat{0.0};
};
