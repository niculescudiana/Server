#include "cthread.h"

CThread::CThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
   // test.show();

}


void CThread::readyRead()
{
    
     message = msocket->readAll();
     qDebug()<<message;

       data = new char[message.size() + 1];
       strcpy(data, message.data());

    qDebug()<<strlen(data)<<" "<<data;
    qDebug()<<strlen("1;a;b")<< " "<<"1;a;b";

      msocket->write("buzz");


    if(strcmp(data,"1;a;b")==0)
        msocket->write("login");

    QString str=data;
    int x=str.split(";")[0].toInt();
    qDebug()<<x;
    if(x==1)
       {
        msocket->write("login");
        msocket->write("user");
    }

    //msocket->write("sal");

}

void CThread::send(const char* data)
{
    msocket->write(data);
}

void CThread::send1()
{
    msocket->write("nu");
}

void CThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";


    msocket->deleteLater();
    exit(0);
}

QByteArray CThread::returndata()
{
    return message;
}


void CThread::run()
{
    // thread starts here
    qDebug() << " Thread started";

    msocket = new QTcpSocket();

    // set the ID
    if(!msocket->setSocketDescriptor(this->socketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(msocket->error());
        return;
    }

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(msocket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(msocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(msocket,SIGNAL(send(const char*)),this,SLOT(send(const char*)));

    // We'll have multiple clients, we want to know which is which
    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies
    msocket->readyRead();

    if(strcmp(data,"1;a;b")==0)
        msocket->write("login");

    //msocket->write(data);

    exec();

}


