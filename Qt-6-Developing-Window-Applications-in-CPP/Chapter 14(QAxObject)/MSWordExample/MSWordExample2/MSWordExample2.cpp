//https://evileg.com/ru/forum/topic/596/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    workWord();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::workWord()
{
    //интерфейс к MSWord
    QAxObject *wordApp = new QAxObject("Word.Application");
    //интерфейс к подобъекту - коллекция скрытых документов
    QAxObject *wordDoc = wordApp->querySubObject("Documents()");
    //создаем новый документ
    QAxObject *newDoc = wordDoc->querySubObject("Add()");

    ///Заголовок для входных данных
    QAxObject *rangeInputData = newDoc->querySubObject("Range()");
    rangeInputData->dynamicCall("SetRange(int, int)", 0, 100);
    rangeInputData->setProperty("Text", "Исходные данные.");

    //размер, шрифт, выравнивание
    QAxObject *font_rangeInputData = rangeInputData->querySubObject("Font");
    font_rangeInputData->setProperty("Size", 12);
    font_rangeInputData->setProperty("Name", "Arial");
    QAxObject *alignment_rangeInputData = rangeInputData->querySubObject("ParagraphFormat");
    alignment_rangeInputData->setProperty("Alignment", "wdAlignParagraphCenter");
    alignment_rangeInputData->setProperty("SpaceAfter", 0);

    //отступ
    rangeInputData->dynamicCall("InsertParagraphAfter()");
    rangeInputData->dynamicCall("InsertParagraphAfter()");

    ///Заголовок для 1 таблицы
    QAxObject *rangeNameT1 = newDoc->querySubObject("Range()");
    rangeNameT1->dynamicCall("SetRange(int, int)", 101, 200);
    rangeNameT1->setProperty("Text", "Таблица 1.");
    //выравнивание
    QAxObject *alignment_rangeNameT1 = rangeNameT1->querySubObject("ParagraphFormat");
    alignment_rangeNameT1->setProperty("Alignment", "wdAlignParagraphLeft");

    //таблица 1
    QAxObject *tables = newDoc->querySubObject("Tables()");
    QAxObject *rangeTable1 = newDoc->querySubObject("Range()");
    rangeTable1->dynamicCall("SetRange(int, int)", 201, 300);
    QAxObject* table1 = tables->querySubObject("Add(Range, NumRows, NumColumns, DefaultTableBehavior, AutoFitBehavior)", rangeTable1->asVariant(), 4, 3, 1, 1);
    //Заполняем таблицу
    //горизонтальные заголовки
    QAxObject *currentCell = table1->querySubObject("Cell(Row, Column)", 1, 1);
    QAxObject *rangeCurrentCell = currentCell->querySubObject("Range()");
    rangeCurrentCell->dynamicCall("InsertAfter(Text)", "Наименование");

    currentCell = table1->querySubObject("Cell(Row, Column)", 1, 2);
    rangeCurrentCell = currentCell->querySubObject("Range()");
    rangeCurrentCell->dynamicCall("InsertAfter(Text)", "Формула");

    currentCell = table1->querySubObject("Cell(Row, Column)", 1, 3);
    rangeCurrentCell = currentCell->querySubObject("Range()");
    rangeCurrentCell->dynamicCall("InsertAfter(Text)", "Значение");
    //вертикальные заголовки
    for (int i = 0; i < 3; i++)
    {
        currentCell = table1->querySubObject("Cell(Row, Column)", i+2, 1);
        rangeCurrentCell = currentCell->querySubObject("Range()");
        QString temp = "Переменная" + QString::number(i);
        rangeCurrentCell->dynamicCall("InsertAfter(Text)", temp);
    }
    //формулы


    //делаем ворд видимым
    wordApp->setProperty("Visible", true);

    delete rangeCurrentCell;
    delete currentCell;
    delete table1;
    delete rangeTable1;
    delete tables;
    delete alignment_rangeNameT1;
    delete rangeNameT1;
    delete alignment_rangeInputData;
    delete font_rangeInputData;
    delete rangeInputData;
    delete newDoc;
    delete wordDoc;
    delete wordApp;

}