#pragma once

#include "funcconvertor.h"
#include <QFile>
#include <QGeoCoordinate>
#include <QList>
#include <QStringList>
#include <QWidget>
#include <tuple>
using namespace std;
namespace Ui {
    class DangerZoneForPlan;
}
using namespace std;
class DangerZoneForPlan : public QWidget {
    Q_OBJECT

  public:
    explicit DangerZoneForPlan (QWidget* parent = nullptr);
    ~DangerZoneForPlan ();

    void setUi (Ui::DangerZoneForPlan* newUi);
    void setDecCoordinates (const QString& newDecCoordinates);
    QGeoCoordinate Direct_Geodetic_Problem (const QGeoCoordinate& StartPoint,
      int distance,
      double angle,
      double height);
    void Calculate_Zone ();
    void Calculate_Arc_Start_End_Point ();
    std::tuple<std::string, std::string> Calculate_Out_DecToMin (double Lat, double Long);
    QGeoCoordinate ZaborVody{ 0.0, 0.0 };
    QGeoCoordinate MestoChs{ 0.0, 0.0 };

  private slots:
    void on_cmbBox_ZaborVody1_currentIndexChanged (int index);

  private:
    Ui::DangerZoneForPlan* ui;
    QString DecCoordinates{ "" };
    QString text_RMK_first{};
    double Dec_Lat{ 0 };
    double Dec_Long{ 0 };

    double Distance{ 0 };
    double Azimuth{ 0 };

    std::vector<std::string> PlanPoints{};
    std::vector<std::string> PlanPointsDec{};

    QList<QStringList> ListPointsZaborVody{};
    void inizialisingCombobox ();
};
