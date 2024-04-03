#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
    ui->setupUi (this);

    //
    myword = new QAxObject ("Word.Application");
    mydocs = myword->querySubObject ("Documents");
    mydocs->dynamicCall ("Add(void)");

    document  = myword->querySubObject ("ActiveDocument");
    paragraph = myword->querySubObject ("Selection");
    mytable   = document->querySubObject ("Tables(int)", 1);
}

MainWindow::~MainWindow ()
{
    delete ui;
}

void MainWindow::on_writeWordPushButton_clicked ()
{

    //
    QAxObject* tables = document->querySubObject ("Tables");
    paragraph->dynamicCall ("TypeText(const QString&)", "2013～2017 ");
    QAxObject* range = paragraph->querySubObject ("Range");
    QVariantList paras;
    paras.append (range->asVariant ());
    paras.append (6);
    paras.append (4);
    tables->querySubObject ("Add(QAxObject*, int, int, QVariant&, QVariant&)", paras);
    mytable = paragraph->querySubObject ("Tables(int)", 1);
    mytable->setProperty ("Style", "тип сетки");
    QAxObject* Borders = mytable->querySubObject ("Borders");
    Borders->setProperty ("InsideLineStyle", 1);
    Borders->setProperty ("OutsideLineStyle", 1);
    QAxObject* cell;
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            for (int j = 0; j < 4; j++) {
                cell = mytable->querySubObject ("Cell(int,int)", (i + 1), (j + 1))->querySubObject ("Range");
                switch (j) {
                    case 0:
                        cell->setProperty ("Text", "年份");
                        break;
                    case 1:
                        cell->setProperty ("Text", "高考人数（万）");
                        break;
                    case 2:
                        cell->setProperty ("Text", "录取人数（万）");
                        break;
                    case 3:
                        cell->setProperty ("Text", "录取率");
                        break;
                    default:
                        break;
                }
            }
            continue;
        }
        /*
          for (int j = 0; j < 4; j++) {
              cell = mytable->querySubObject ("Cell(int,int)", (i + 1), (j + 1))->querySubObject ("Range");
              switch (j) {
                  case 0:
                      cell->setProperty ("Text", myrecord [i - 1].year);
                      break;
                  case 1:
                      cell->setProperty ("Text", myrecord [i - 1].total);
                      break;
                  case 2:
                      cell->setProperty ("Text", myrecord [i - 1].admit);
                      break;
                  case 3:
                      cell->setProperty ("Text", myrecord [i - 1].rate);
                      break;
                  default:
                      break;
              }
          }
      */
    }
    document->dynamicCall ("SaveAs(const QString&)", "G:\\ProjectQT\\656.doc");
    QMessageBox::information (this, tr ("Сохранение"), tr ("Таблица экспортирована в документ Word."));
    delete mytable;
    mytable = nullptr;
    delete paragraph;
    paragraph = nullptr;
    document->dynamicCall ("Close()");
    myword->dynamicCall ("Quit()");

    // все ок
    QMessageBox::information (this, tr ("Работа с документом"), tr ("Документ Word сохранен.。"));
    ui->writeWordPushButton->setEnabled (false);
    ui->readWordPushButton->setEnabled (true);
}

void MainWindow::on_readWordPushButton_clicked ()
{
    myword = new QAxObject ("Word.Application");
    mydocs = myword->querySubObject ("Documents");
    mydocs->dynamicCall ("Open(const QString&)", "G:\\ProjectQT\\Qt62.doc");
    document       = myword->querySubObject ("ActiveDocument");
    paragraph      = document->querySubObject ("Range()");
    QString outStr = paragraph->property ("Text").toString ();
    ui->OutWordLabel->setText (outStr.split ("H").at (0));
    paragraph = document->querySubObject ("Range(QVariant, QVariant)", 14, 30);
    outStr    = paragraph->property ("Text").toString ();
    delete paragraph;
    paragraph = nullptr;
    document->dynamicCall ("Close()");
    myword->dynamicCall ("Quit()");
    QMessageBox::information (this, tr ("消息"), outStr);
    ui->writeWordPushButton->setEnabled (true);
    ui->readWordPushButton->setEnabled (false);
}
