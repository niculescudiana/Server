#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
#include "cthread.h"

class CServer: public QTcpServer
{
    Q_OBJECT
public:
    explicit CServer(QObject* parent = 0);
    void startServer();

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

private:

};

#endif // CSERVER_H
