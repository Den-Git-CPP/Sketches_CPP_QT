#include "specialwidget.h"

SpecialWidget::SpecialWidget(QWidget *parent) : QWidget(parent) {
  QPalette pe;
  QFont font;
  pe.setColor(QPalette::WindowText, Qt::black);
  font.setBold(true);
  font.setPointSize(11);

  this->setFixedSize(1280, 730);
  this->setWindowFlags(Qt::FramelessWindowHint); // скрыть строку меню

  QStandardItemModel *model = new QStandardItemModel();
  QStringList labels{};
  labels << "Заголовок1"
         << "Заголовок2"
         << "Заголовок3";
  model->setHorizontalHeaderLabels(labels);

  // Определить товар
  QStandardItem *item = 0;
  for (int i = 0; i < 1000; i++) {
    item = new QStandardItem(QString("%1").arg(i));
    model->setItem(i, 0, item);
    item = new QStandardItem(QString("%1").arg(i * 2));
    model->setItem(i, 1, item);
    item = new QStandardItem(QString("%1").arg(i * 3));
    model->setItem(i, 2, item);
    item = new QStandardItem(QString("%1").arg(i * 4));
    model->setItem(i, 3, item);
    item = new QStandardItem(QString("%1").arg(i * 5));
    model->setItem(i, 4, item);
  }

  tableView = new QTableView(this);
  tableView->setFixedSize(1280, 670);
  tableView->setShowGrid(true);
  tableView->setGridStyle(Qt::SolidLine);
  tableView->setModel(model);
  tableView->setSelectionBehavior(
      QAbstractItemView::SelectRows); // select a line
  tableView->horizontalHeader()->setHighlightSections(false);
  tableView->verticalHeader()->setVisible(false);
  tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  tableView->setStyleSheet(
      "QHeaderView::section { background-color:green; color:white};");
  int totalRow = tableView->model()->rowCount(); // the total row
  int rowHeight = tableView->rowHeight(0);       // the row's height
  int tableViewHeight = tableView->height();     // every row's height
  int row1page = tableViewHeight / rowHeight - 1;
  int totalPage = totalRow / row1page;
  if (totalRow % row1page != 0)
    totalPage++;

  QPushButton *last_btn = new QPushButton(tr("Предыдущий"), this);
  last_btn->setFixedSize(80, 30);
  last_btn->setPalette(pe);
  last_btn->setFont(font);
  connect(last_btn, &QPushButton::clicked, this, &SpecialWidget::lastBtn_click);

  page_edit = new QLineEdit(QString::number(1), this);
  page_edit->setFixedSize(50, 30);
  page_edit->setPalette(pe);
  page_edit->setFont(font);
  connect(page_edit, &QLineEdit::editingFinished, this, &SpecialWidget::pageTo);

  QLabel *totalPage_label =
      new QLabel(QString("/") + QString::number(totalPage), this);
  totalPage_label->setFixedSize(50, 30);
  totalPage_label->setPalette(pe);
  totalPage_label->setFont(font);

  QPushButton *next_btn = new QPushButton(tr("Следующая страница"), this);
  next_btn->setFixedSize(80, 30);
  next_btn->setPalette(pe);
  next_btn->setFont(font);
  connect(next_btn, &QPushButton::clicked, this, &SpecialWidget::nextBtn_click);

  QHBoxLayout *second_layout = new QHBoxLayout();
  second_layout->setSpacing(3);
  second_layout->addStretch(1);
  second_layout->addWidget(last_btn);
  second_layout->addWidget(page_edit);
  second_layout->addWidget(totalPage_label);
  second_layout->addWidget(next_btn);
  second_layout->addStretch(1);

  QVBoxLayout *mainSec_layout = new QVBoxLayout();
  mainSec_layout->addStretch(2);
  mainSec_layout->addLayout(second_layout);
  mainSec_layout->addSpacing(2);
  this->setLayout(mainSec_layout);
  /*
      QAbstractButton *btn = tableView->findChild<QAbstractButton*>();
      if(btn)
      {
          btn->setStyleSheet("QTableCornerButton::section{background-color:green}");
      }*/
  QScrollBar *scrollBar = (QScrollBar *)tableView->verticalScrollBar();
  connect(scrollBar, SIGNAL(valueChanged(int)), this, SLOT(scrollMove(int)));
}

SpecialWidget::~SpecialWidget() {}

void SpecialWidget::lastBtn_click() {
  int page = page_edit->text().toInt();
  if (page <= 1)
    return;

  int rowHeight = tableView->rowHeight(0);   // the row's height
  int tableViewHeight = tableView->height(); // every row's height
  int row1page = tableViewHeight / rowHeight - 1;
  tableView->verticalScrollBar()->setSliderPosition((page - 2) * row1page);
  page_edit->setText(QString::number(page - 1));
}

void SpecialWidget::nextBtn_click() {
  int page = page_edit->text().toInt();

  int totalRow = tableView->model()->rowCount(); // the total row
  int rowHeight = tableView->rowHeight(0);       // the row's height
  int tableViewHeight = tableView->height();     // every row's height
  int row1page = tableViewHeight / rowHeight - 1;
  int totalPage = totalRow / row1page;
  if (totalRow % row1page != 0)
    totalPage++;

  tableView->verticalScrollBar()->setSliderPosition((page + 1) * row1page);
  if (page + 1 <= totalPage)
    page_edit->setText(QString::number(page + 1));
}

void SpecialWidget::pageTo() {
  if (page_edit->text().isEmpty())
    return;

  int totalRow = tableView->model()->rowCount(); // the total row
  int rowHeight = tableView->rowHeight(0);       // the row's height
  int tableViewHeight = tableView->height();     // every row's height
  int row1page = tableViewHeight / rowHeight - 1;
  int totalPage = totalRow / row1page;
  if (totalRow % row1page != 0)
    totalPage++;

  int page = page_edit->text().toInt();
  if (page <= 0)
    page = 1;
  else if (page > totalPage)
    page = totalPage;
  page_edit->setText(QString::number(page));

  tableView->verticalScrollBar()->setSliderPosition(row1page * (page - 1));
}

void SpecialWidget::scrollMove(int) {
  qDebug() << "scrollMove";

  int totalRow = tableView->model()->rowCount(); // the total row
  int rowHeight = tableView->rowHeight(0);       // the row's height
  int tableViewHeight = tableView->height();     // every row's height
  int row1page = tableViewHeight / rowHeight - 1;
  int totalPage = totalRow / row1page;
  if (totalRow % row1page != 0)
    totalPage++;

  int last = 0;
  int current = tableView->verticalScrollBar()->value();
  int next = row1page;
  for (int page = 1; page <= totalPage; page++) {
    if (current > last && current < next) {
      page_edit->setText(QString::number(page));
      break;
    }
    last += row1page;
    next += row1page;
  }
  if (current >= row1page * (totalPage - 1))
    page_edit->setText(QString::number(totalPage));
}
