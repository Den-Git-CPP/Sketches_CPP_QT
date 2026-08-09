#include "funcconvertor.h"

QString func::Calculate_DecCoordinate (const QString& Grad_Lat,
  const QString& Min_Lat,
  const QString& Sec_Lat,
  const QString& Grad_Long,
  const QString& Min_Long,
  const QString& Sec_Long)
{
    //_in: 55°44'44".920 37°37'24".942  _out QString: 55.745811 37.623595
    double Dec_Long = Grad_Long.toDouble () + (Min_Long.toDouble () / 60) +
                      (Sec_Long.toDouble () / 3600);
    double Dec_Lat = Grad_Lat.toDouble () + (Min_Lat.toDouble () / 60) +
                     (Sec_Lat.toDouble () / 3600);
    return QString::number (Dec_Lat, 'd', 6) + " " + QString::number (Dec_Long, 'd', 6);
}

std::tuple<double, double, double, double, double, double>
func::Calculate_GeoCoordinates (const QString& in_DecCoordinates)
{ //// _in: "55.745811 37.623595" _out: 55 44 44 37 37 24

    // для расчёта геодезических координат
    double Degree_Lat{ 0 }, Minutes_Lat{ 0 }, Seconds_Lat{ 0 };
    double Degree_Long{ 0 }, Minutes_Long{ 0 }, Seconds_Long{ 0 };

    // целая часть запишется в Degree_Lat, дробная - в Minutes_Lat
    Degree_Lat  = in_DecCoordinates.first (9).toDouble (); // широта
    Degree_Long = in_DecCoordinates.last (9).toDouble ();  // долгота

    Minutes_Lat  = std::modf (Degree_Lat, &Degree_Lat);
    Minutes_Long = std::modf (Degree_Long, &Degree_Long);

    Seconds_Lat = std::modf (Minutes_Lat * 60.0, &Minutes_Lat);
    Seconds_Lat = round ((Seconds_Lat * 60.0) * 1000) / 1000;

    Seconds_Long = std::modf (Minutes_Long * 60.0, &Minutes_Long);
    Seconds_Long = round ((Seconds_Long * 60.0) * 1000) / 1000;

    return std::make_tuple (Degree_Lat, Minutes_Lat, Seconds_Lat, Degree_Long,
      Minutes_Long, Seconds_Long);
}

QString func::GeoCoord_DoubleToString (const double& Degree_Lat,
  const double& Minutes_Lat,
  const double& Seconds_Lat,
  const double& Degree_Long,
  const double& Minutes_Long,
  const double& Seconds_Long)
{ // корректный перевод координат double для вывода как string
    //_in: 55 44 1 37 37 1    _out:"554401373701"
    QString Degree_Lat_Str = QString::number (static_cast<int> (Degree_Lat));
    if (static_cast<int> (Degree_Lat) < 10) {
        Degree_Lat_Str = "0" + QString::number (static_cast<int> (Degree_Lat));
    }
    else {
        Degree_Lat_Str = QString::number (static_cast<int> (Degree_Lat));
    }

    QString Minutes_Lat_Str = QString::number (static_cast<int> (Minutes_Lat));
    if (static_cast<int> (Minutes_Lat) < 10) {
        Minutes_Lat_Str = "0" + QString::number (static_cast<int> (Minutes_Lat));
    }
    else {
        Minutes_Lat_Str = QString::number (static_cast<int> (Minutes_Lat));
    }

    QString Seconds_Lat_Str = QString::number (Seconds_Lat, 'd', 3);
    if (static_cast<int> (Seconds_Lat) < 10) {
        Seconds_Lat_Str = "0" + QString::number (static_cast<int> (Seconds_Lat));
    }
    else {
        Seconds_Lat_Str = QString::number (static_cast<int> (Seconds_Lat));
    }

    QString Degree_Long_Str = QString::number (static_cast<int> (Degree_Long));
    if (static_cast<int> (Degree_Long) < 10) {
        Degree_Long_Str = "0" + QString::number (static_cast<int> (Degree_Long));
    }
    else {
        Degree_Long_Str = QString::number (static_cast<int> (Degree_Long));
    }

    QString Minutes_Long_Str = QString::number (static_cast<int> (Minutes_Long));
    if (static_cast<int> (Minutes_Long) < 10) {
        Minutes_Long_Str = "0" + QString::number (static_cast<int> (Minutes_Long));
    }
    else {
        Minutes_Long_Str = QString::number (static_cast<int> (Minutes_Long));
    }

    QString Seconds_Long_Str = QString::number (Seconds_Long, 'd', 3);
    if (static_cast<int> (Seconds_Long) < 10) {
        Seconds_Long_Str = "0" + QString::number (static_cast<int> (Seconds_Long));
    }
    else {
        Seconds_Long_Str = QString::number (static_cast<int> (Seconds_Long));
    }

    QString GeoCoord_Dbl_Str = Degree_Lat_Str + Minutes_Lat_Str + Seconds_Lat_Str +
                               Degree_Long_Str + Minutes_Long_Str + Seconds_Long_Str;
    return GeoCoord_Dbl_Str;
}
