#pragma once
#include <QString>
#include <tuple>
namespace func {
    // расчет десятичных координат
    QString Calculate_DecCoordinate (const QString& Grad_Lat,
      const QString& Min_Lat,
      const QString& Sec_Lat,
      const QString& Grad_Long,
      const QString& Min_Long,
      const QString& Sec_Long);

    //// расчет геодезических координат
    std::tuple<double, double, double, double, double, double>
    Calculate_GeoCoordinates (const QString& in_DecCoordinates);
    QString GeoCoord_DoubleToString (const double& Grad_Lat,
      const double& Min_Lat,
      const double& Sec_Lat,
      const double& Grad_Long,
      const double& Min_Long,
      const double& Sec_Long);
} // namespace func
