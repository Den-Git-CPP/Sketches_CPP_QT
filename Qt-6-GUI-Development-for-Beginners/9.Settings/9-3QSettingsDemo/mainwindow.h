#pragma once

#include <QMainWindow>
#include <QSettings>
#include <QDebug>
#include <QDateTime>
#include <QFileDialog>
#include <QSlider>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

struct CheckBoxInfo {
    QString settingsName;
    QCheckBox* checkBox;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow (QWidget* parent = nullptr);
    ~MainWindow ();
  private slots:

    void on_pushButton_clicked ();

    void on_pushButton_2_clicked ();

    void on_horizontalSlider_sliderMoved (int position);

  private:
    void on_Save_triggered ();
    void on_Load_triggered ();

    Ui::MainWindow* ui;
    QVector<CheckBoxInfo> m_checkBoxes;
};
