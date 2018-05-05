#include "cclienthandler.h"
#include "cdatabase.h"
CClientHandler::CClientHandler()
{

}

void CClientHandler::handleCommand(QString str)
{
    CDataBase* DataBase;
    DataBase=DataBase->getInstance();

    int x=str.split(";")[0].toInt();
    qDebug()<<x;

    if(x==1)
       {
        qDebug()<<"x este 1";

        std::string username=str.split(";")[1].toStdString();
        std::string password=str.split(";")[2].toStdString();
        bool ok = DataBase->verifyLogin(username,password);
        if(ok==0)
            qDebug() <<"Cont invalid";
        else if(ok==1)
             qDebug() <<"Cont valid";
        message="login";
        //msocket->write("login");
    }
    if(x==2){
        qDebug()<<"x este 2";
        QString username=str.split(";")[1];
        QString password=str.split(";")[2];
        //qDebug()<<username.c_str();
        bool ok = DataBase->verifyUnregisteredUser(username,password);
        if(ok==0)
            qDebug() <<"Cont invalid";
        else if(ok==1)
             qDebug() <<"Cont valid";
        //msocket->write("register");
        message="register";
    }
}

const char* CClientHandler::getMessage()
{
    return message;
}
