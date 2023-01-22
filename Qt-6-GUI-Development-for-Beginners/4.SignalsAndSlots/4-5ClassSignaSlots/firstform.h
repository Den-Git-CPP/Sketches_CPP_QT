#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FirstForm; }
QT_END_NAMESPACE

class FirstForm : public QMainWindow
{
    Q_OBJECT

public:
    FirstForm(QWidget *parent = nullptr);


    ~FirstForm();
signals:
    void newTextEntered(const QString &text);

private slots:
    void onTextBoxReturnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FirstForm *ui;
};
