#pragma once

#include <QDebug>
#include <QFont>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPalette>
#include <QPushButton>
#include <QScrollBar>
#include <QSlider>
#include <QStandardItemModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QWidget>

class SpecialWidget : public QWidget {
  Q_OBJECT
public:
  SpecialWidget(QWidget *parent = 0);
  ~SpecialWidget();

  QLineEdit *page_edit;
  QTableView *tableView;

public slots:
  void lastBtn_click();
  void nextBtn_click();
  void pageTo();
  void scrollMove(int value);
};
