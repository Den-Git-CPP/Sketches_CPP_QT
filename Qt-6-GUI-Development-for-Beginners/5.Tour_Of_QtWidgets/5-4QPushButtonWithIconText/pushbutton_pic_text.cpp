#include "pushbutton_pic_text.h"
#include "./ui_pushbutton_pic_text.h"

pushButton_Pic_Text::pushButton_Pic_Text (QWidget* parent) : QMainWindow (parent), ui (new Ui::pushButton_Pic_Text)
{
    ui->setupUi (this);
}

pushButton_Pic_Text::~pushButton_Pic_Text ()
{
    delete ui;
}

void pushButton_Pic_Text::Use_the_systems_own_API ()
{

    ui->pushButton->setIconSize (QSize (32, 32));
    ui->pushButton->setIcon (QIcon (":/images/meteo.ico"));
    ui->pushButton->setText (QString::fromLocal8Bit ("Navigation"));
    ui->pushButton->setStyleSheet ("QPushButton{border:1px solid blue;background:white;}"
                                   "QPushButton:hover{border:0px;background:blue;}"
                                   "QPushButton:pressed{border:0px;background:red;}");
}

void pushButton_Pic_Text::TextUnderIcon ()
{
    ui->toolButton->setIconSize (QSize (32, 32));
    ui->toolButton->setIcon (QIcon (":/images/meteo.ico"));
    ui->toolButton->setText (QString::fromLocal8Bit ("Navigation (TextUnderIcon)"));
    ui->toolButton->setToolButtonStyle (Qt::ToolButtonTextUnderIcon);
}

void pushButton_Pic_Text::PushButtonWithLayouts ()
{
    ui->pushButton_2->setText (" "); // очистить текст иначе виден под Layouts
    QLabel* iconLabel = new QLabel ();
    QLabel* textLabel = new QLabel ();

    iconLabel->setStyleSheet ("border:1px solid red;");
    textLabel->setStyleSheet ("border:1px solid red;");

    iconLabel->setMaximumSize (48, 48);
    iconLabel->setPixmap (QPixmap (":/images/meteo.ico"));
    iconLabel->setScaledContents (true);
    iconLabel->setAlignment (Qt::AlignCenter);

    textLabel->setText (QString::fromLocal8Bit ("Navigation (Layouts)"));
    textLabel->setFixedWidth (120);

    QHBoxLayout* myLayout = new QHBoxLayout ();
    myLayout->addSpacing (10);
    myLayout->addWidget (iconLabel);
    myLayout->addSpacing (20);
    myLayout->addWidget (textLabel);
    myLayout->addStretch ();

    ui->pushButton_2->setLayout (myLayout);
    ui->pushButton_2->setStyleSheet ("QPushButton{border:1px solid blue;background:white;}"
                                     "QPushButton:hover{border:0px;background:blue;}"
                                     "QPushButton:pressed{border:0px;background:red;}");
}

void pushButton_Pic_Text::on_pushButton_clicked ()
{
    Use_the_systems_own_API ();
}

void pushButton_Pic_Text::on_toolButton_clicked ()
{
    TextUnderIcon ();
}

void pushButton_Pic_Text::on_pushButton_2_clicked ()
{
    PushButtonWithLayouts ();
}
