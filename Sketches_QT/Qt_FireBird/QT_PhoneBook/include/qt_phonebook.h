#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

#include <QVBoxLayout>

class QT_PhoneBook : public QWidget {
    Q_OBJECT

  public:
    QT_PhoneBook (QWidget* parent = nullptr);
    ~QT_PhoneBook ();

  private:
    QLabel* lbl_FIO              = nullptr;
    QLineEdit* l_edit_FIO        = nullptr;
    QLabel* lbl_TlfNumber        = nullptr;
    QLineEdit* l_edit_TlfNumber  = nullptr;
    QLabel* lbl_Department       = nullptr;
    QLineEdit* l_edit_Department = nullptr;
    QVBoxLayout* vbox            = nullptr;
};
