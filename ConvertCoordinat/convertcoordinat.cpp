#include "convertcoordinat.h"


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

    label_in = new QLabel();
    label_in->setFont(*ft);
    label_in->setPalette(*pa);
    label_in->setAlignment(Qt::AlignLeft);
    label_in->setText("Введите десятичные координаты");
    
    label_prim = new QLabel();
    label_prim->setFont(*ft);
    label_prim->setPalette(*pa);
    label_prim->setAlignment(Qt::AlignCenter);
    label_prim->setText("Пример:55.661535, 37.641491");
    
 
    label_dol = new QLabel();
    label_dol->setFont(*ft);
    label_dol->setPalette(*pa);
    label_dol->setAlignment(Qt::AlignLeft);
  //  label_dol->setText("ВНИМАНИЕ ВВЕДЕНЫ \nДЕСЯТИЧНЫЕ КООРДИНАТЫ:");


    label_shir = new QLabel();
    label_shir->setFont(*ft);
    label_shir->setPalette(*pa);
    label_shir->setAlignment(Qt::AlignLeft);
//    label_shir->setText("Проверьте широту");

    lnEdit_in_coord= new QLineEdit();
    lnEdit_in_coord->setInputMask("99.999999, 99.999999;_");  // Дата: ##.##.####
    connect(lnEdit_in_coord, SIGNAL(textEdited(QString)),this, SLOT(ProvCoordinat()));

    vbox= new QVBoxLayout();
    vbox->addWidget(label_in);
    vbox->addWidget(label_prim);
    vbox->addWidget(lnEdit_in_coord);

    vbox->addWidget(label_dol);
    vbox->addWidget(label_shir);

    this->setLayout(vbox);

}

ConvertCoordinat::~ConvertCoordinat()
{

}

void ConvertCoordinat::ProvCoordinat()
{
     label_dol->setText("ВНИМАНИЕ ВВЕДЕНЫ \nДЕСЯТИЧНЫЕ КООРДИНАТЫ:\n"+label_shir->text());
}
