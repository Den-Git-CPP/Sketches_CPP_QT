#include <QByteArray>
#include <QCoreApplication>
#include <QString>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString text = "Привет,%20мир!";
    QByteArray utf8Data = QTextCodec::codecForName("UTF-8")->fromUnicode(text);
    //Обратно
    //QString text = QTextCodec::codecForName("UTF-8")->toUnicode(utf8Data);

    QByteArray Win1251Data = QTextCodec::codecForName("windows-1252")->fromUnicode(text);
    qDebug()<< utf8Data.data();
    qDebug()<< Win1251Data.data();

    return a.exec();
}
