#include <QFile>
#include <QStringList>
#include <QDebug>

int main()
{
    QFile file(":/FlightParam.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"Error: " << file.errorString();
        return 1;
    }

    QStringList wordList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        wordList.append(line.split(',').first());
    }

    qDebug() << wordList;
   
    return 0;
}
