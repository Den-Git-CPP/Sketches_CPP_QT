#include "convertcoordinat.h"
#include "./ui_convertcoordinat.h"

convertcoordinat::convertcoordinat (QWidget* parent)
: QWidget (parent),
  ui (new Ui::convertcoordinat)
{
    ui->setupUi (this);
    Set_Hide_Show_Wiget (false);
    connect (ui->bt_res, &QPushButton::pressed, [=] () {
        Calculate (ui->tab->currentIndex ());
    }); // слот для расчета координат

    connect (ui->tab, &QTabWidget::currentChanged, [=] () {
        SetTextResBtn (ui->tab->currentIndex ());
    }); // слот изменение нажатия названия кнопки при нажатии на Tab

    connect (ui->tab, &QTabWidget::currentChanged, [=] () {
        Set_Hide_Show_Wiget (false);
    }); // скрывает виджеты
}

convertcoordinat::~convertcoordinat ()
{
    delete ui;
}

void convertcoordinat::Calculate (int tab_index)
{
    if (tab_index == 0) {
        DecCoordinates = ui->lnEdit_in_coord->text (); // 55.745811 37.623595
    }

    if (tab_index == 1) { // 55°44'44" 37°37'24"

        DecCoordinates =
          func::Calculate_DecCoordinate (ui->lnEdit_in_grad_lat_page2->text (), //
            ui->lnEdit_in_min_lat_page2->text (),   //
            ui->lnEdit_in_sec_lat_page2->text (),   //
            ui->lnEdit_in_grad_long_page2->text (), //
            ui->lnEdit_in_min_long_page2->text (),  //
            ui->lnEdit_in_sec_long_page2->text ());
    }

    // DecCoordinates="55.745811 37.623595";
    std::tie (Degree_Lat, Minutes_Lat, Seconds_Lat, Degree_Long, Minutes_Long,
      Seconds_Long) = func::Calculate_GeoCoordinates (DecCoordinates);
    print_Coordinates (0);
}

void convertcoordinat::print_Coordinates (int tab_index)
{ //
    QString coord_str{};

    if (tab_index == 0) {
        coord_str = func::GeoCoord_DoubleToString (Degree_Lat, Minutes_Lat,
          Seconds_Lat, Degree_Long, Minutes_Long, Seconds_Long);
        ui->label_GEO->setText ("Десятичные координаты:\n" + DecCoordinates //
                                + "\n\nГeодезические координаты\nШирота: " +
                                coord_str.insert (2, "°")
                                  .insert (5, "'")
                                  .insert (8, "'' 0")
                                  .insert (14, "°")
                                  .insert (17, "'")
                                  .append ("''"));
    }
    coord_str = func::GeoCoord_DoubleToString (Degree_Lat, Minutes_Lat,
      Seconds_Lat, Degree_Long, Minutes_Long, Seconds_Long);
    ui->label_GEO_plan->setText (

      "Координаты для плана полёта:\n" +
      coord_str.replace (4, 2, "N0").remove (10, 2).append ("E"));
    // показали Labels
    Set_Hide_Show_Wiget (true);
}

void convertcoordinat::SetTextResBtn (int tab_index)
{
    if (tab_index == 0) {
        ui->bt_res->setText (
          "Перевести из десятичных координат в\nгеодезические координаты.");
    }
    if (tab_index == 1) {
        ui->bt_res->setText (
          "Перевести из геодезических координат в\n десятичные координаты.");
    }
}

void convertcoordinat::Set_Hide_Show_Wiget (bool settings)
{
    ui->label_GEO->setVisible (settings);
    ui->label_GEO_plan->setVisible (settings);
    ui->pushButton_ShowMap->setVisible (settings);
    ui->pushButton_DangerZone->setVisible (settings);
}

void convertcoordinat::on_pushButton_ShowMap_clicked ()
{
    QString res{
        "https://yandex.ru/maps/213/moscow/?ll=" //
        + QString::number (Degree_Long + Minutes_Long / 60 + Seconds_Long / 3600) //
        + "%2C" //
        + QString::number (Degree_Lat + Minutes_Lat / 60 + Seconds_Lat / 3600) //
        + "&mode=whatshere&whatshere%5Bpoint%5D=" //
        + QString::number (Degree_Long + Minutes_Long / 60 + Seconds_Long / 3600) //
        + "%2C" //
        + QString::number (Degree_Lat + Minutes_Lat / 60 + Seconds_Lat / 3600) //
        + "&whatshere%5Bzoom%5D=14&z=14"
    };

    QDesktopServices::openUrl (res);
}

void convertcoordinat::on_pushButton_DangerZone_clicked ()
{ //MestoChs (55.635300, 37.531700);  // 19     Большой Коньковский пруд  55º 38' 07"037º 31' 54" 55.635300, 37.531700
    // DecCoordinates       = "55.635300, 37.531700";//MestoChs
    danger_zone_for_plan = new DangerZoneForPlan;
    danger_zone_for_plan->setDecCoordinates (DecCoordinates);
    danger_zone_for_plan->show ();
}
