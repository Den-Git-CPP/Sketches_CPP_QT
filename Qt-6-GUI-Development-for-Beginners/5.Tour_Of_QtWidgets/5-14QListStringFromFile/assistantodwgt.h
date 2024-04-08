#pragma once

#include <QWidget>
#include <QString>
#include <QStringList>

#include <QFile>
#include <QMessageBox>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
    class AssistantODWgt;
}
QT_END_NAMESPACE

class AssistantODWgt : public QWidget {
    Q_OBJECT

  public:
    AssistantODWgt (QWidget* parent = nullptr);
    ~AssistantODWgt ();

  private slots:
    void on_btn_Command_clicked ();

  private:
    Ui::AssistantODWgt* ui;
    int FirstComand{ 0 };             // счетчик команд
    QList<QString> strList_FIO{};     // QList содержит ФИО сотрудников
    QList<QString> strList_Command{}; // QList содержит алгоритм действий сотрудников

    void LoadData (QStringList& strlist_data, const QString& path_data);
};
