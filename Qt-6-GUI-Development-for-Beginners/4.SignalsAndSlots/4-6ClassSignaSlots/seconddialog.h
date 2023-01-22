#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>
#include "ui_seconddialog.h"

class SecondDialog : public QDialog, public Ui::SecondDialog
{
    Q_OBJECT

public:
    explicit SecondDialog(QWidget *parent = 0);
    ~SecondDialog();
};

#endif // SECONDDIALOG_H
