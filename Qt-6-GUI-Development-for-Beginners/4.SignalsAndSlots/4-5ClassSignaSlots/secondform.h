#pragma once

#include <QMainWindow>

namespace Ui {
class SecondForm;
}

class SecondForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondForm(QWidget *parent = nullptr);
    ~SecondForm();
public slots:
    void onNewTextEntered(const QString &text);

private:
    Ui::SecondForm *ui;
};

