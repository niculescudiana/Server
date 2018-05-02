#include "cserver.h"
#include "cthread.h"
#include "cdatabase.h"

CServer::CServer(QObject *parent) :
    QTcpServer(parent)
{
}

void CServer::startServer()
{
    int port = 1234;
    QHostAddress ip;
    ip.setAddress("172.20.10.3");

    if(!this->listen(ip, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";

    }

    CDataBase* Database;
    Database = Database->getInstance();
    Database->setDataBase();

}

// This function is called by QTcpServer when a new connection is available.
void CServer::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    // Every new connection will be run in a newly created thread
  // if(thread==0)
   CThread *thread= new CThread(socketDescriptor, this);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
    
}


