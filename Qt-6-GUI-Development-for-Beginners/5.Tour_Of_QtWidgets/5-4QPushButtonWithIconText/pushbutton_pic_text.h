#pragma once

#include <QMainWindow>

#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class pushButton_Pic_Text; }
QT_END_NAMESPACE

class pushButton_Pic_Text : public QMainWindow
{
    Q_OBJECT

public:
    pushButton_Pic_Text(QWidget *parent = nullptr);
   ~pushButton_Pic_Text();

   void Use_the_systems_own_API();
   void TextUnderIcon();
   void PushButtonWithLayouts();
   private slots:
   void on_pushButton_clicked();
   void on_toolButton_clicked();

   void on_pushButton_2_clicked();

   private:
    Ui::pushButton_Pic_Text *ui;
};
