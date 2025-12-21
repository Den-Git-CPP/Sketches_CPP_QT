#pragma once

#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QStringList>
#include <QWidget>

#include <QDate>
#include <QDateTime>

class QSqlDatabase;
namespace Ui {
    class Add_DBF;
}

class Add_DBF : public QWidget {
    Q_OBJECT

  public:
    explicit Add_DBF (QWidget* parent = nullptr);
    ~Add_DBF ();

  signals:
    void AllDBFilesReady ();

  private slots:
    void on_p_Button_1DBF_clicked ();
    void on_p_Button_2DBF_clicked ();
    void on_p_Button_Compare_clicked ();

  private:
    Ui::Add_DBF* ui;

    QString addPathDB ();
    bool fileTransferAndRenameDB (const QString& oldPath, const QString& newPath);
};
