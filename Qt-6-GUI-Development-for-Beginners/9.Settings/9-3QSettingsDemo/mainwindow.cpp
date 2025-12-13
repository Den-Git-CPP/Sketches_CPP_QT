#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
    ui->setupUi (this);
    // До чтения или записи настроек нужно заполнить этот вектор данными о чекбоксах.
    m_checkBoxes = {
        { "checkBox_1",   ui->checkBox },
        { "checkBox_2", ui->checkBox_2 },
        { "checkBox_3", ui->checkBox_3 },
        { "checkBox_4", ui->checkBox_4 },
        { "checkBox_5", ui->checkBox_5 },
        { "checkBox_6", ui->checkBox_6 }
    };
}

MainWindow::~MainWindow ()
{
    delete ui;
}

void MainWindow::on_Save_triggered ()
{
    QDate date = QDate::currentDate (); // получаем текущую дату
    QTime time = QTime::currentTime (); // получаем текущее время

    /* записываем имя файла с настройками,
     * qApp->applicationDirPath()   - директория где лежит exe файл проекта
     * QString("/%0_%1.ini")        - формируем имя файла в формате .ini специальный формат для хранения настроек
     * date.toString("dd-MM-yyyy")  - дата - в формате день недели_месяц_год
     * time.toString("hh-mm")       - время в формате часы_минуты_секунды
     */
    QString fileName = qApp->applicationDirPath ().append (QString ("/%0_%1.ini").arg (date.toString ("dd-MM-yyyy")).arg (time.toString ("hh-mm")));

    QSettings settings (fileName, QSettings::IniFormat);
    settings.beginGroup ("checkBox");
    /*
    settings.setValue ("checkBox_1", ui->checkBox->isChecked ());
    settings.setValue ("checkBox_2", ui->checkBox_2->isChecked ());
    settings.setValue ("checkBox_3", ui->checkBox_3->isChecked ());
    settings.setValue ("checkBox_4", ui->checkBox_4->isChecked ());
    settings.setValue ("checkBox_5", ui->checkBox_5->isChecked ());
    settings.setValue ("checkBox_6", ui->checkBox_6->isChecked ());
*/
    for (auto& checkBoxInfo : m_checkBoxes) {
        settings.setValue (checkBoxInfo.settingsName, checkBoxInfo.checkBox->isChecked ());
    }
    settings.endGroup ();

    settings.beginGroup ("slider");
    settings.setValue ("horizontalSlider", ui->horizontalSlider->value ());
    settings.endGroup ();
}

void MainWindow::on_Load_triggered ()
{
    // создаем переменную fileName куда запишется путь до выбранного нами файла
    QString fileName = QFileDialog::getOpenFileName (0, "Open", "/", "");
    QSettings settings (fileName, QSettings::IniFormat);

    settings.beginGroup ("checkBox");
    /* присваваем checkBox значение считанное из файла для этого указываем "ключ" т.е. имя "checkBox_1"
     * далее после запятой пишем значение по умолчанию, на случай если не будет считано значение из файла "false"
     * далее указываем тип значения .toBool() т.е. получаем значения true или false.
     */
    /*
    ui->checkBox->setChecked (settings.value ("checkBox_1", false).toBool ());
    ui->checkBox_2->setChecked (settings.value ("checkBox_2", false).toBool ());
    ui->checkBox_3->setChecked (settings.value ("checkBox_3", false).toBool ());
    ui->checkBox_4->setChecked (settings.value ("checkBox_4", false).toBool ());
    ui->checkBox_5->setChecked (settings.value ("checkBox_5", false).toBool ());
    ui->checkBox_6->setChecked (settings.value ("checkBox_6", false).toBool ());
*/
    for (auto& checkBoxInfo : m_checkBoxes) {
        checkBoxInfo.checkBox->setChecked (settings.value (checkBoxInfo.settingsName, false).toBool ());
    }
    settings.endGroup ();

    // вот пример со слайдером  тип значения для него .toInt()
    settings.beginGroup ("slider");
    ui->horizontalSlider->setValue (settings.value ("horizontalSlider", 0).toInt ());
    settings.endGroup ();
}

void MainWindow::on_pushButton_clicked ()
{
    on_Save_triggered ();
}

void MainWindow::on_pushButton_2_clicked ()
{
    on_Load_triggered ();
}

void MainWindow::on_horizontalSlider_sliderMoved (int position)
{
    ui->label->setText (QString::number (position));
}
