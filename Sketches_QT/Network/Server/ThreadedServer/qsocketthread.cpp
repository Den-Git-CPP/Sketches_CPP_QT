#include "qsocketthread.h"

QSocketThread::QSocketThread(int descriptror, QObject *parent) : QThread(parent), socketDescriptror(descriptror)
{

}

QSocketThread::~QSocketThread()
{
    delete socket;
}

void QSocketThread::run()
{
    socket=new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptror);

    connect(socket, SIGNAL(readyRead()),this , SLOT(onReadyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),this , SLOT(onDisconnected()),Qt::DirectConnection);

    exec();
}

void QSocketThread::onReadyRead()
{
    qDebug()<<socket->readAll();

    QString response ="HTTP/1.1 200 OK\r\n\r\n%1";
    socket->write(response.arg(QTime::currentTime().toString()).toLatin1());
    socket->disconnectFromHost();
}

void QSocketThread::onDisconnected()
{
    socket->disconnect();
    socket->close();
    quit();
}
