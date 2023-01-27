#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  downloader = new Downloader(); // Инициализируем Downloader

  // по нажатию кнопки запускаем получение данных по http
  connect(
    ui->pushButton, &QPushButton::clicked, downloader, &Downloader::getData);
  // по окончанию получения данных считываем данные из файл
  connect(downloader, &Downloader::onReady, this, &Widget::readFile);
}

Widget::~Widget()
{
  delete ui;
}

void
Widget::readFile()
{
  QFile file("G:/file.xml");
  if (!file.open(QIODevice::ReadOnly)) // Открваем файл, если это возможно
    return;
  // если открытие файла невозможно, выходим из слота
  // в противном случае считываем данные и устанавилваем их в textEdit
  ui->textEdit->setText(file.readAll());
}
