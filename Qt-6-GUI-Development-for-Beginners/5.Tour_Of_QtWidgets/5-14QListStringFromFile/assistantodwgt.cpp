#include "assistantodwgt.h"
#include "./ui_assistantodwgt.h"

AssistantODWgt::AssistantODWgt (QWidget* parent) : QWidget (parent), ui (new Ui::AssistantODWgt)
{
    ui->setupUi (this);
    // инициализация списков
    LoadData (strList_FIO, ":/resource/FIO.txt");
    LoadData (strList_Command, ":/resource/Algorithm.txt");

    ui->btn_Command->setText (strList_Command.at (FirstComand));
}

AssistantODWgt::~AssistantODWgt ()
{
    delete ui;
}
/**
 * @brief AssistantODWgt::LoadData
 * @param strlist_data  QList для заполнения данных списков Команд и ФИО
 * @param path_data путь до файлов с командами и ФИО
 */
void AssistantODWgt::LoadData (QStringList& strlist_data, const QString& path_data)
{
    QFile dataTextFile{ path_data };
    if (!dataTextFile.open (QIODevice::ReadOnly)) {
        QMessageBox::information (0, "Error opening file", dataTextFile.errorString ());
    }
    else {
        while (!dataTextFile.atEnd ()) {
            strlist_data.append (dataTextFile.readLine ());
        }

        dataTextFile.close ();
    }
}

void AssistantODWgt::on_btn_Command_clicked ()
{
    /* при нажатии кнопки текст меняется на следущую комнду согласно алгоритма
     */
    if (FirstComand < strList_Command.size ()) {
        ui->btn_Command->setText (strList_Command.at (FirstComand));
        FirstComand++;
    }
    else {
        FirstComand = 0;
    }
}
