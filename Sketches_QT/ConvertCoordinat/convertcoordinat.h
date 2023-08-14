#pragma once

#include <QWidget>
#include <math.h>
#include <tuple>

QT_BEGIN_NAMESPACE
namespace Ui {
class convertcoordinat;
}
QT_END_NAMESPACE

class convertcoordinat : public QWidget {
  Q_OBJECT

public:
  convertcoordinat(QWidget *parent = nullptr);
  ~convertcoordinat();

private slots:
  void Calculate(int tab_index);
  // устанавливает название кнопки
  void SetTextResBtn(int tab_index);

private:
  Ui::convertcoordinat *ui;
  // для расчёта геодезических координат
  double Degree_Lat{0}, Minutes_Lat{0}, Seconds_Lat{0};
  double Degree_Long{0}, Minutes_Long{0}, Seconds_Long{0};
  // для расчёта десятичных координат
  double Dec_Lat{0}, Dec_Long{0};

  // расчет геодезических координат
  void CalculateGeoCoordinates(const QString &str);
  // расчет десятичных координат
  void CalculateDecCoordinates(const QString &Grad_Lat, const QString &Min_Lat,
                               const QString &Sec_Lat, const QString &Grad_Long,
                               const QString &Min_Long,
                               const QString &Sec_Long);
  // создате ссылку для Yandex Карт
  QString YandexMap(double Degree_Long, double Minutes_Long,
                    double Seconds_Long, double Degree_Lat, double Minutes_Lat,
                    double Seconds_Lat);

  void Set_Hide_Show_Wiget(bool settings);

  // выводим инфрмацию
  void print_Coordinates();
};
