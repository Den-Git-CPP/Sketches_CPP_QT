#ifndef QSIMPLESERVER_H
#define QSIMPLESERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>
#include "qsocketthread.h"

class QSimpleServer : public QTcpServer
{
    Q_OBJECT
public:
    QSimpleServer(QObject *parent=0);
    void incomingConnection(int handle);

};

#endif // QSIMPLESERVER_H
