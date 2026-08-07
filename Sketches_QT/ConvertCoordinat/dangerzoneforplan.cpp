#include "dangerzoneforplan.h"
#include "ui_dangerzoneforplan.h"

DangerZoneForPlan::DangerZoneForPlan (QWidget* parent) : QWidget (parent), ui (new Ui::DangerZoneForPlan)
{
    ui->setupUi (this);
}

DangerZoneForPlan::~DangerZoneForPlan ()
{
    delete ui;
}

void DangerZoneForPlan::setUi (Ui::DangerZoneForPlan* newUi)
{
    ui = newUi;
}

void DangerZoneForPlan::setDecCoordinates (const QString& inDecCoordinates)
{

    //    QGeoCoordinate ZaborVody (55.794200, 37.761100); // 34     Серебряно – Виноградный пруд         55º 47' 39"037º 45' 40" 55.794200, 37.761100
    //    QGeoCoordinate MestoChs (55.635300, 37.531700);  // 19     Большой Коньковский пруд             55º 38' 07"037º 31' 54" 55.635300, 37.531700

    DecCoordinates = inDecCoordinates;
    ui->label_Coord_Chs1->setText ("Координаты места ЧС: " + inDecCoordinates);

    ZaborVody.setLatitude (55.794200);
    ZaborVody.setLongitude (37.761100);

    Dec_Lat  = inDecCoordinates.first (9).toDouble ();
    Dec_Long = inDecCoordinates.last (9).toDouble ();

    MestoChs.setLatitude (Dec_Lat);
    MestoChs.setLongitude (Dec_Long);

    // MestoChs.setLatitude (55.635300);
    // MestoChs.setLongitude (37.531700);

    Calculate_Zone ();
    inizialisingCombobox ();
}

QGeoCoordinate DangerZoneForPlan::Direct_Geodetic_Problem (const QGeoCoordinate& StartPoint, int distance, double angle, double height)
{ // Direct_Geodetic_Problem
    QGeoCoordinate EndPoint = StartPoint.atDistanceAndAzimuth (distance, angle, height);
    return EndPoint;
}

void DangerZoneForPlan::Calculate_Arc_Start_End_Point ()
{
    std::vector<QGeoCoordinate> ZaborVodyPoints{};
    std::vector<QGeoCoordinate> MestoChsPoints{};

    double azimuth_Points_Start = Azimuth + 90.0;
    double azimuth_Points_End   = Azimuth + 270.0;
    PlanPoints.clear ();

    while (azimuth_Points_Start < azimuth_Points_End) {
        QGeoCoordinate calculate_point_for_ZaborVody = Direct_Geodetic_Problem (ZaborVody, 5000, azimuth_Points_Start, 0);
        ZaborVodyPoints.push_back (calculate_point_for_ZaborVody);

        QGeoCoordinate calculate_point_for_MestoChsPoints = Direct_Geodetic_Problem (MestoChs, 5000, azimuth_Points_Start + 180, 0);
        MestoChsPoints.push_back (calculate_point_for_MestoChsPoints);

        azimuth_Points_Start += 15.0;
    }

    for (auto point : ZaborVodyPoints) {
        PlanPoints.push_back (Calculate_Out_DecToMin (point.latitude (), point.longitude ()));
    };
    for (auto point : MestoChsPoints) {
        PlanPoints.push_back (Calculate_Out_DecToMin (point.latitude (), point.longitude ()));
    };
}

string DangerZoneForPlan::Calculate_Out_DecToMin (double Lat, double Long)
{
    //
    QString QDecToMin1{};
    int Degree_Lat  = abs (Lat);  // Широта
    int Degree_Long = abs (Long); // Долгота

    int Minutes_Long = (Long - static_cast<int> (abs (Long))) * 60;
    int Minutes_Lat  = (Lat - static_cast<int> (abs (Lat))) * 60;

    int Seconds_Long = ((Long - Degree_Long) * 60 - static_cast<int> (abs ((Long - Degree_Long)) * 60)) * 60;
    int Seconds_Lat  = ((Lat - Degree_Lat) * 60 - static_cast<int> (abs ((Lat - Degree_Lat) * 60))) * 60;

    int Seconds_Long_dbl = static_cast<int> (round (Seconds_Long));
    int Seconds_Lat_dbl  = static_cast<int> (round (Seconds_Lat));

    QString Seconds_Lat_dbl_str{};
    QString Seconds_Long_dbl_str{};

    if (Seconds_Lat < 10) {
        Seconds_Lat_dbl_str = "0" + QString::number (Seconds_Lat_dbl);
    }
    else {
        Seconds_Lat_dbl_str = QString::number (Seconds_Lat_dbl);
    };
    if (Seconds_Long < 10) {
        Seconds_Long_dbl_str = "0" + QString::number (Seconds_Long_dbl);
    }
    else {
        Seconds_Long_dbl_str = QString::number (Seconds_Long_dbl);
    };

    QDecToMin1 = QString::number (Degree_Lat)     //
                 + QString::number (Minutes_Lat)  //
                 + Seconds_Lat_dbl_str            //+ Seconds_Lat_dbl_str
                 + "N0"                           //
                 + QString::number (Degree_Long)  //
                 + QString::number (Minutes_Long) //
                 + Seconds_Long_dbl_str           // + Seconds_Long_dbl_str
                 + "E";
    return QDecToMin1.toStdString ();
}

void DangerZoneForPlan::Calculate_Zone ()
{
    Distance = ZaborVody.distanceTo (MestoChs);
    Azimuth  = ZaborVody.azimuthTo (MestoChs);
    // посчитали зону
    Calculate_Arc_Start_End_Point ();
    //  // вывели
    //  for (auto point : PlanPoints) {
    //      qDebug () << QString::fromStdString (point);
    //  }
}


void DangerZoneForPlan::inizialisingCombobox ()
{   //QComboBox одновременно отображется не более 10 элементов, метод setMaxVisibleItems(10)
    QFile dataTextFile{ ":/resource/ZaborVody.txt" };
    if (!dataTextFile.open (QIODevice::ReadOnly)) {
        qDebug () <<  "Error opening file", dataTextFile.errorString ();
    }
    else {
        while (!dataTextFile.atEnd ()) {
            QString line=dataTextFile.readLine().trimmed();
            QStringList list_point =line.split(QLatin1Char('/'));
            ListPointsZaborVody.append (list_point);
         }
        dataTextFile.close ();
        ListPointsZaborVody.removeFirst();
    }
    for (auto LinePoint: ListPointsZaborVody) {
        ui->cmbBox_ZaborVody1->addItem(LinePoint.at(0).toLatin1());
        ui->cmbBox_ZaborVody2->addItem(LinePoint.at(0).toLatin1());
    }
}

void DangerZoneForPlan::on_cmbBox_ZaborVody1_currentIndexChanged(int index)
{   QString text_RMK{"Забор Воды № "+ListPointsZaborVody.at(index).at(0)
                     +" \n"+ListPointsZaborVody.at(index).at(1)
                     +" \nКоординаты:" +ListPointsZaborVody.at(index).at(3)
            +" "+ListPointsZaborVody.at(index).at(4)
    };
    //CalculateDecCoordinates("00","00","00","00","00","00","00","00");
    ui->TextZonaRMK1->setText(text_RMK);
    //qDebug()<<"on_cmbBox_ZaborVody1_currentIndexChanged"<<ui->cmbBox_ZaborVody1->currentIndex();
}
/**
Расстояние между ZaborVody->MestoChs: 22.7741 км
Аzimuth ZaborVody->MestoChs: 219.214 °
=================
"554921N0374156E"
"554950N0374251E"
"555010N0374357E"
"555020N0374510E"
"555018N0374626E"
"555006N0374738E"
"554944N0374842E"
"554913N0374933E"
"554836N0375009E"
"554755N0375026E"
"554713N0375024E"
"554632N0375002E"
"553624N0373536E"
"553555N0373441E"
"553535N0373335E"
"553526N0373222E"
"553527N0373108E"
"553539N0372956E"
"553601N0372852E"
"553632N0372801E"
"553709N0372726E"
"553750N0372708E"
"553832N0372710E"
"553913N0372732E"
*/

void DangerZoneForPlan::on_cmbBox_ZaborVody1_activated(int index)
{

}

