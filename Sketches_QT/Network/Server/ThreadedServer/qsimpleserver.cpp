#include "qsimpleserver.h"

QSimpleServer::QSimpleServer(QObject *parent):QTcpServer(parent)
{
    if(listen(QHostAddress::Any,81)){
        qDebug()<<"Listening....";
    }
    else{
        qDebug()<<"Error while starting: "<< errorString();
    }
}

void QSimpleServer::incomingConnection(int handle)
{
    QSocketThread *thread =new QSocketThread(handle);

    connect(thread,SIGNAL(finished()), thread,SLOT(deleteLater()));
    thread->start();

}

