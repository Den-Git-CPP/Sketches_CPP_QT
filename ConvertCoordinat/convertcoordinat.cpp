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
     
    label_att = new QLabel(this);
    label_att->setFont(*ft);
    label_att->setPalette(*pa);
    label_att->setAlignment(Qt::AlignLeft);

    lnEdit_in_coord= new QLineEdit(this);
    lnEdit_in_coord->setInputMask("99.999999, 99.999999;_");  // Маска координаты: ##.######, ##.######
    connect(lnEdit_in_coord, SIGNAL(editingFinished()),this, SLOT(ProvCoordinat()));

    bt_res= new QPushButton("Перевести из десятичных координат в\n геодезические координаты.");
    bt_res->setIcon(QIcon (":/resource/Zvezda.jpg"));
    bt_res->setIconSize(QSize(45, 45));
    bt_res->setFont(*ft);
    connect(bt_res,&QPushButton::pressed,[=](){
      Calculate(lnEdit_in_coord->text());
    });

    label_dol = new QLabel(this);
    label_dol->setFont(*ft);
    label_dol->setPalette(*pa);
    label_dol->setAlignment(Qt::AlignLeft);

    vbox= new QVBoxLayout(this);
    vbox->addWidget(label_in);
    vbox->addWidget(label_prim);
    vbox->addWidget(lnEdit_in_coord);
    vbox->addWidget(label_att);
    vbox->addWidget(bt_res);
    vbox->addWidget(label_dol);


    this->setLayout(vbox);

}

ConvertCoordinat::~ConvertCoordinat()
{

}

void ConvertCoordinat::ProvCoordinat()
{
    label_att->setText("ВНИМАНИЕ ВВЕДЕНЫ \nДЕСЯТИЧНЫЕ КООРДИНАТЫ:\n"+lnEdit_in_coord->text());
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
}
