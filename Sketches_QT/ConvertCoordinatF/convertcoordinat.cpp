#include "convertcoordinat.h"
#include "./ui_convertcoordinat.h"


convertcoordinat::convertcoordinat (QWidget* parent) : QWidget (parent), ui (new Ui::convertcoordinat)
{
    ui->setupUi (this);
    // устанавливаем специальную политику отображения меню
    setContextMenuPolicy (Qt::CustomContextMenu);
    connect (this, SIGNAL (customContextMenuRequested (QPoint)), this, SLOT (customContextMenuShow (QPoint)));

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
        CalculateGeoCoordinates (ui->lnEdit_in_coord->text ());
        print_Coordinates ();
    }

    if (tab_index == 1) {
        CalculateDecCoordinates (ui->lnEdit_in_grad_lat_page2->text (), ui->lnEdit_in_min_lat_page2->text (), ui->lnEdit_in_sec_lat_page2->text (),
          ui->lnEdit_in_grad_long_page2->text (), ui->lnEdit_in_min_long_page2->text (), ui->lnEdit_in_sec_long_page2->text ());

        QString str11 = QString::number (Dec_Lat, 'd', 6) + " " + QString::number (Dec_Long, 'd', 6);

        CalculateGeoCoordinates (str11); // формат 99.999999 99.999999
        print_Coordinates ();
    }
}

void convertcoordinat::CalculateGeoCoordinates (const QString& str)
{
    // 55.745811,  55°44'44".920
    // 37.623595,  37°37'24".942

    double Lat  = str.first (9).toDouble (); // широта
    double Long = str.last (9).toDouble ();  // долгота
    // целая часть запишется в Degree_Lat, дробная - в Minutes_Lat

    Minutes_Lat  = std::modf (Lat, &Degree_Lat);
    Minutes_Long = std::modf (Long, &Degree_Long);

    Seconds_Lat = std::modf (Minutes_Lat * 60.0, &Minutes_Lat);
    Seconds_Lat = round ((Seconds_Lat * 60.0) * 1000) / 1000;

    Seconds_Long = std::modf (Minutes_Long * 60.0, &Minutes_Long);
    Seconds_Long = round ((Seconds_Long * 60.0) * 1000) / 1000;
}

void convertcoordinat::print_Coordinates ()
{

    QString Degree_Lat_Str = QString::number (static_cast<int> (Degree_Lat));
    if (static_cast<int> (Degree_Lat) < 10) {
        Degree_Lat_Str = "0" + QString::number (static_cast<int> (Degree_Lat));
    }

    QString Minutes_Lat_Str = QString::number (static_cast<int> (Minutes_Lat));
    if (static_cast<int> (Minutes_Lat) < 10) {
        Minutes_Lat_Str = "0" + QString::number (static_cast<int> (Minutes_Lat));
    }

    QString Seconds_Lat_Str = QString::number (Seconds_Lat, 'd', 3);
    if (static_cast<int> (Seconds_Lat) < 10) {
        Seconds_Lat_Str = "0" + QString::number (static_cast<int> (Seconds_Lat));
    }

    QString Degree_Long_Str = QString::number (static_cast<int> (Degree_Long));
    if (static_cast<int> (Degree_Long) < 10) {
        Degree_Long_Str = "0" + QString::number (static_cast<int> (Degree_Long));
    }

    QString Minutes_Long_Str = QString::number (static_cast<int> (Minutes_Long));
    if (static_cast<int> (Minutes_Long) < 10) {
        Minutes_Long_Str = "0" + QString::number (static_cast<int> (Minutes_Long));
    }

    QString Seconds_Long_Str = QString::number (Seconds_Long, 'd', 3);
    if (static_cast<int> (Seconds_Long) < 10) {
        Seconds_Long_Str = "0" + QString::number (static_cast<int> (Seconds_Long));
    }

    ui->label_GEO->setText ("Десятичные координаты:\n" + ui->lnEdit_in_coord->text () + "\n\nГeодезические координаты\nШирота: " + Degree_Lat_Str + "° " + Minutes_Lat_Str
                            + "' " + Seconds_Lat_Str + "'' " + "Долгота: " + Degree_Long_Str + "° " + Minutes_Long_Str + "' " + Seconds_Long_Str + "'' ");

    ui->label_GEO_plan->setText ("Координаты для плана полёта:\n" + Degree_Lat_Str + Minutes_Lat_Str +
                                 /*QString::number(round((Seconds_Lat * 10) / 10)) +*/ "N0" + Degree_Long_Str + Minutes_Long_Str +
                                 /*QString::number(round((Seconds_Lat * 10) / 10)) +*/ "E");

    ui->label_GEO_map->setText (YandexMap (Degree_Lat, Minutes_Lat, Seconds_Lat, Degree_Long, Minutes_Long, Seconds_Long));
    ui->label_GEO_map->setOpenExternalLinks (true);
    ui->label_GEO_map->setTextInteractionFlags (Qt::LinksAccessibleByMouse);

    // показали Labels
    Set_Hide_Show_Wiget (true);
}

void convertcoordinat::CalculateDecCoordinates (
  const QString& Grad_Lat, const QString& Min_Lat, const QString& Sec_Lat, const QString& Grad_Long, const QString& Min_Long, const QString& Sec_Long)
{ //
    // 55.745811,  55°44'44".920
    // 37.623595,  37°37'24".942
    Dec_Long = Grad_Long.toDouble () + (Min_Long.toDouble () / 60) + (Sec_Long.toDouble () / 3600);
    Dec_Lat  = Grad_Lat.toDouble () + (Min_Lat.toDouble () / 60) + (Sec_Lat.toDouble () / 3600);
}

void convertcoordinat::SetTextResBtn (int tab_index)
{
    if (tab_index == 0) {
        ui->bt_res->setText ("Перевести из десятичных координат в\nгеодезические координаты.");
    }
    if (tab_index == 1) {
        ui->bt_res->setText ("Перевести из геодезических координат в\n десятичные координаты.");
    }
}

void convertcoordinat::customContextMenuShow (const QPoint& pos)
{
    QPoint globalPos      = mapToGlobal (pos);
    QClipboard* clipboard = QApplication::clipboard ();
    QMenu menu (this);

    QAction* Copy_the_coordinate = menu.addAction (QString ("СКОПИРОВАТЬ КООРДИНАТУ"));
    QAction* selected_action     = menu.exec (globalPos);

    if (selected_action) {

        if (selected_action == Copy_the_coordinate) {
            if (ui->label_GEO->hasSelectedText ()) {
                clipboard->setText (ui->label_GEO->selectedText ());
            }
            else if (ui->label_GEO_plan->hasSelectedText ())
                clipboard->setText (ui->label_GEO_plan->selectedText ());
        }
    }
}

QString convertcoordinat::YandexMap (double Degree_Long, double Minutes_Long, double Seconds_Long, double Degree_Lat, double Minutes_Lat, double Seconds_Lat)
{
    QString res{ "<a href=\"https://yandex.ru/maps/213/moscow/?ll=" + QString::number (Degree_Lat + Minutes_Lat / 60 + Seconds_Lat / 3600) + "%2C"
                 + QString::number (Degree_Long + Minutes_Long / 60 + Seconds_Long / 3600)
                 + "&mode=whatshere&whatshere%5Bpoint%5D=" + QString::number (Degree_Lat + Minutes_Lat / 60 + Seconds_Lat / 3600) + "%2C"
                 + QString::number (Degree_Long + Minutes_Long / 60 + Seconds_Long / 3600) + "&whatshere%5Bzoom%5D=14&z=14\">Посмотреть на карте</a><br>" };
    return res;
}

void convertcoordinat::Set_Hide_Show_Wiget (bool settings)
{
    ui->label_GEO->setVisible (settings);
    ui->label_GEO_plan->setVisible (settings);
    ui->label_GEO_map->setVisible (settings);
}
