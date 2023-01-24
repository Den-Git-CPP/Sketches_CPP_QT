#include "convertcoordinat.h"
#include <string>

ConvertCoordinat::ConvertCoordinat(QWidget *parent)
{
 this->resize(180,70);
 this->setWindowTitle("Конвертор координат");
 this->setWindowFlags(Qt::Window
                            |Qt::WindowCloseButtonHint);
    icon=new QIcon (":/resource/avia.png");
    this->setWindowIcon(*icon); // Значок для окна
    //Палетка для шрифтов Label
    ft=     new QFont("Arial", 12, QFont::Bold); // Устанавливаем размер шрифта
    pa=     new QPalette();
    pa->setColor(QPalette::WindowText,Qt::darkBlue); // Устанавливаем цвет шрифта

    label_in = new QLabel(this);
    label_in->setFont(*ft);
    label_in->setPalette(*pa);
    label_in->setAlignment(Qt::AlignLeft);
    label_in->setText("Введите десятичные координаты");
    
    label_prim = new QLabel(this);
    label_prim->setFont(*ft);
    label_prim->setPalette(*pa);
    label_prim->setAlignment(Qt::AlignLeft);
    label_prim->setText("Пример:55.661535, 37.641491");

    lnEdit_in_coord= new QLineEdit(this);
    lnEdit_in_coord->setInputMask("99.999999, 99.999999;_");  // Маска координаты: ##.######, ##.######
    lnEdit_in_coord->setText("55.661535, 37.641491");

    bt_res= new QPushButton("Перевести из десятичных координат в\nгеодезические координаты.");
    bt_res->setIcon(QIcon (":/resource/zvezda1.jpg"));
    bt_res->setIconSize(QSize(45, 45));
    bt_res->setFont(*ft);
    connect(bt_res,&QPushButton::pressed,[=](){
      Calculate(lnEdit_in_coord->text());
    });

    label_GEO = new QLabel(this);
    label_GEO->setFont(*ft);
    label_GEO->setPalette(*pa);
    label_GEO->setAlignment(Qt::AlignLeft);

    label_GEO_map = new QLabel(this);

    vbox= new QVBoxLayout(this);
    vbox->addWidget(label_in);
    vbox->addWidget(label_prim);
    vbox->addWidget(lnEdit_in_coord);
    vbox->addWidget(bt_res);
    vbox->addWidget(label_GEO);
    vbox->addWidget(label_GEO_map);

    this->setLayout(vbox);

}

ConvertCoordinat::~ConvertCoordinat()
{

}

void ConvertCoordinat::Calculate(const QString &str)
{
double Long =str.first(9).toFloat();//долгота
double Lat =str.last(9).toFloat();// широта

Degree_Long= abs(Long);
Degree_Lat=abs(Lat);

Minutes_Long= (Long-static_cast<int>(abs(Long)))*60;
Minutes_Lat= (Lat-static_cast<int>(abs(Lat)))*60;

Seconds_Long= round((((Long-Degree_Long)*60- static_cast<int>(abs((Long-Degree_Long))*60))*60)*100)/100;// округлено до второй цифра после запятой
Seconds_Lat=  round((((Lat-Degree_Lat)*60- static_cast<int>(abs((Lat-Degree_Lat)*60)))*60)*100)/100;// округлено до второй цифра после запятой


label_GEO->setText( "Десятичные координаты:\n"
                    +lnEdit_in_coord->text()
                    +"\n\nГeодезические координаты\nДолгота: "
                    +QString::number(Degree_Long)+"° "
                    +QString::number(Minutes_Long) +"' "
                    +QString::number(Seconds_Long) +"'' "
                    +"Широта: "
                    +QString::number(Degree_Lat)+"° "
                    +QString::number(Minutes_Lat) +"' "
                    +QString::number(Seconds_Lat) +"'' "
                    +"\n\nДля плана полёта:\n"
                   +QString::number(Degree_Long)
                   +QString::number(Minutes_Long)
                   +QString::number(round((Seconds_Long*10)/10))
                   +"N0"
                   +QString::number(Degree_Lat)
                   +QString::number(Minutes_Lat)
                   +QString::number(round((Seconds_Long*10)/10))
                   +"E"
                   );
label_GEO_map->setText("<a href=\"https://google.ru/\">Это карта </a><br>");
label_GEO_map->setOpenExternalLinks(true);
label_GEO_map->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

}
