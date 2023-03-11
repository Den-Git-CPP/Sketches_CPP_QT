#ifndef QSOCKETTHREAD_H
#define QSOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QTime>

class QSocketThread : public QThread
{
    Q_OBJECT
public:
    explicit QSocketThread(int descriptror, QObject *parent = nullptr);
    ~QSocketThread();
    void run();
private:
    int socketDescriptror;
    QTcpSocket *socket;

public slots:
    void onReadyRead();
    void onDisconnected();

};

#endif // QSOCKETTHREAD_H
