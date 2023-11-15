#pragma once

#include <QWidget>
#include <QFileSystemModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addDirButton_clicked();

    void on_removeFileDir_clicked();

private:
    Ui::Widget *ui;
    QFileSystemModel * model;
};
