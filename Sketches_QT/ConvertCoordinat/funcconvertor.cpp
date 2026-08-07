#include "funcconvertor.h"

QString func::Calculate_DecCoordinate(const QString &Grad_Lat, const QString &Min_Lat, const QString &Sec_Lat, const QString &Grad_Long, const QString &Min_Long, const QString &Sec_Long)
{
    //_in: 55°44'44".920 37°37'24".942  _out QString: 55.745811 37.623595
    double Dec_Long = Grad_Long.toDouble () + (Min_Long.toDouble () / 60) + (Sec_Long.toDouble () / 3600);
    double Dec_Lat  = Grad_Lat.toDouble () + (Min_Lat.toDouble () / 60) + (Sec_Lat.toDouble () / 3600);
    return QString::number (Dec_Lat, 'd', 6) + " " + QString::number (Dec_Long, 'd', 6);
}

std::tuple<double, double, double, double, double, double> func::Calculate_GeoCoordinates(const QString &in_DecCoordinates)
{        //// _in: 55.745811 37.623595 _out: 55°44'44" 37°37'24"

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

        return std::make_tuple(Degree_Lat,Minutes_Lat,Seconds_Lat,Degree_Long,Minutes_Long,Seconds_Long);
}
