#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStandardItem>
#include <QStandardItemModel>
#include <QStringList>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // 1. размер по окну главного окна
  int width = this->width();
  int height = this->height();
  ui->tableView->resize(width, height);

  // 2. отображение и отмена линии сетки таблицы
  // ui->tableView->setShowGrid(true);
  ui->tableView->setShowGrid(false);

  // 3. кисть для линии сетки
  // enum Qt::PenStyle
  // Qt::NoPen                  0	нет линий вообще.
  // Qt::SolidLine              1	Простая линия.
  // Qt::DashLine               2	Черточки разделенные несколькими пикселями.
  // Qt::DotLine                3	Точки разделенные несколькими пикселями.
  // Qt::DashDotLine	          4	Штрихпунктирная линия.
  // Qt::DashDotDotLine	        5	Одна черточка, две точки, одна черточка, две
  // точки. Qt::CustomDashLine	6	Пользовательский шаблон определенный
  // используя

  // ui->tableView->setGridStyle(Qt::DashLine);
  ui->tableView->setGridStyle(Qt::DashDotLine);

  // 4. функция сортировки по столбцам включена
  ui->tableView->setSortingEnabled(true);

  // 5. Установка заголовка столбцов
  // используем модель
  QStandardItemModel *model = new QStandardItemModel();
  QStringList labels{};
  labels << "Заголовок1"
         << "Заголовок2"
         << "Заголовок3";
  model->setHorizontalHeaderLabels(labels);
  ui->tableView->setModel(model);
  ui->tableView->show();

  // 6. Заполнить содержание таблицы
  QStandardItem *item{0};
  for (int i = 0; i < 10; i++) {
    item = new QStandardItem(QString("%1").arg(i));
    model->setItem(i, 0, item);
    item = new QStandardItem(QString("%1").arg(i * 2));
    model->setItem(i, 1, item);
    item = new QStandardItem(QString("%1").arg(i * 3));
    model->setItem(i, 2, item);
  }
  // 7. Очистка модели
  // model->clear();

  // 8. Использовние стилей CSS
  // border: none;                           таблица не имеет границ
  // selection-background-color: #8EDE21;    цвет фона в выбранных ячейках
  // color: red                              цвет шрифта красный
  //
  ui->tableView->setStyleSheet("QTableView{ "
                               "border: none;"
                               "selection-background-color: #8EDE21;"
                               "color: red}");
}

MainWindow::~MainWindow() { delete ui; }
