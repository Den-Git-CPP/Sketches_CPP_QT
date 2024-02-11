#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
    ui->setupUi (this);
}

MainWindow::~MainWindow ()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked ()
{
    QString JsonFilePath = "./resource/QtJson.json";
    QFile File (JsonFilePath);
    if (File.open (QIODevice::ReadOnly)) {
        QByteArray Bytes = File.readAll ();
        File.close ();

        QJsonParseError JsonError;
        QJsonDocument Document = QJsonDocument::fromJson (Bytes, &JsonError);
        if (JsonError.error != QJsonParseError::NoError) {
            qDebug () << "Error in Json Data: " << JsonError.errorString ();
            return;
        }
        else {
            qDebug () << "No any Error in Json Data: ";
        }

        if (Document.isObject ()) {
            QJsonObject Obj = Document.object ();
            qDebug () << Obj.value ("Data_11").toString ();
            qDebug () << Obj.value ("Data_21").toString ();
            qDebug () << Obj.value ("Data_31").toString ();
            qDebug () << Obj.value ("Data_41").toString ();
            qDebug () << Obj.value ("Data_51").toString ();
            qDebug () << Obj.value ("Data_61").toString ();
            qDebug () << Obj.value ("Data_71");
            qDebug () << Obj.value ("Data_71").toDouble ();

            Obj ["Data_11"] = "New Value1";
            Obj ["Data_21"] = "New Value2";

            qDebug () << Obj.value ("Data_11").toString ();
            qDebug () << Obj.value ("Data_21").toString ();

            QJsonArray JArray = Obj.value ("PointsData").toArray ();
            for (auto points : JArray) {

                QJsonObject ObjPoints = points.toObject ();

                ObjPoints ["Width"]  = 300;
                ObjPoints ["Height"] = 400;

                qDebug () << ObjPoints.value ("Width").toInt () //
                          << " "                                //
                          << ObjPoints.value ("Height").toInt ();

                points = ObjPoints;
            }

            Obj ["PointsData"]  = JArray;
            QJsonArray JArray_1 = Obj.value ("PointsData").toArray ();

            for (auto points : JArray_1) {
                QJsonObject ObjPoints = points.toObject ();
                qDebug () << ObjPoints.value ("Width").toInt () //
                          << " "                                //
                          << ObjPoints.value ("Height").toInt ();
            }
            // WriteJsonData
            if (File.open (QIODevice::ReadWrite | QIODevice::Truncate)) {
                Document.setObject (Obj);
                File.write (Document.toJson (QJsonDocument::JsonFormat::Indented)); // Format::Compact
                File.encodeName ("UTF-8");
                File.close ();
            }
        }
    }
}
