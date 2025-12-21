#include "include/add_dbf.h"
#include "source/ui_add_dbf.h"

Add_DBF::Add_DBF (QWidget* parent) : QWidget (parent), ui (new Ui::Add_DBF)
{
    ui->setupUi (this);
    connect (this, &Add_DBF::AllDBFilesReady, [=] () {
        close ();
    });
}

Add_DBF::~Add_DBF ()
{
    delete ui;
}

void Add_DBF::on_p_Button_1DBF_clicked ()
{
    ui->l_Edit_1DBF->setText (addPathDB ());
}

void Add_DBF::on_p_Button_2DBF_clicked ()
{
    ui->l_Edit_2DBF->setText (addPathDB ());
}

QString Add_DBF::addPathDB ()
{
      QString path_bd = QFileDialog::getOpenFileName (this, "Укажите путь к базе БД",
      QApplication::applicationDirPath () + QDir::separator () + "DB" + QDir::separator (), // path to /app/DB
      "Firebird (*.FDB)");
    return path_bd;
}

bool Add_DBF::fileTransferAndRenameDB (const QString& oldPath, const QString& newPath)
{
    // Попробуем сначала простое переименование (самое эффективное)
    if (QFile::rename (oldPath, newPath)) {
        return true;
    }
    // Если переименование не удалось, возвращаемся к копированию и удалению
    qWarning () << "Не удалось переименовать. Попытка копирования/удаления "
                   "как резервного варианта.";
    if (QFile::copy (oldPath, newPath)) {
        if (QFile::remove (oldPath)) {
            qDebug () << "Файл успешно перемещен путем копирования/удаления.";
            return true;
        }
        else {
            qWarning () << "ОШИБКА: Копирование выполнено успешно, но не удалось "
                           "удалить исходный файл!";
            // Handle cleanup/error logging here
            return false;
        }
    }
    else {
        qWarning () << "ОШИБКА: Не удалось скопировать файл.\n";

        return false;
    }
}

void Add_DBF::on_p_Button_Compare_clicked ()
{
    QStringList sortedFiles{};
    sortedFiles << ui->l_Edit_1DBF->text () << ui->l_Edit_2DBF->text ();

    // сравнить по дате переименовать
    for (const QString& files : sortedFiles) {
        // просмотрели инфу
        if (!files.isEmpty ()) {
            QFileInfo info (files);
            // время последнего модифицирования
            QDateTime lastModifiedTime = info.lastModified ().toLocalTime ();
            // абсолютный старый путь до файла
            QString oldPath_DB = info.absoluteFilePath ();
            // нормализовали путь
            oldPath_DB = QDir::cleanPath (oldPath_DB);
            // путь где будет новый файл
            QString newPath_DB = QApplication::applicationDirPath () + QDir::separator () + "DB" + QDir::separator () + info.baseName ()
                                 + lastModifiedTime.toString ("_ddMMyyyy_hhmmss.") + info.completeSuffix ();
            // нормализовали путь
            newPath_DB = QDir::cleanPath (newPath_DB);
            // пытаемся скопровать файл
            if (!fileTransferAndRenameDB (oldPath_DB, newPath_DB)) {
                qWarning () << "ОШИБКА:\n";
            }
        }
    }

    emit AllDBFilesReady ();
}

