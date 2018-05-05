#ifndef CTHREAD_H
#define CTHREAD_H
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include"cdatabase.h"
class CThread : public QThread
{
    Q_OBJECT

private:
    QTcpSocket *msocket;
    qintptr socketDescriptor;
    QByteArray message;
    char* data;
    //CDataBase* Database;

public:
    explicit CThread(qintptr ID, QObject *parent = 0);

    void run();
    QByteArray returndata();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();
    void send(const char* data);
};


#endif // CTHREAD_H


