#pragma once

#include <QMainWindow>

namespace Ui {
class QT_PhoneBook;
}

class QT_PhoneBook : public QMainWindow {
  Q_OBJECT

public:
  QT_PhoneBook(QWidget *parent = nullptr);
  ~QT_PhoneBook();

private:
  Ui::QT_PhoneBook *ui;
};
