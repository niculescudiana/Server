#include "cclienthandler.h"
#include "cdatabase.h"
#include "croomlist.h"

CClientHandler::CClientHandler()
{

}

void CClientHandler::handleCommand(QString str)
{
    CDataBase* DataBase;
    DataBase=DataBase->getInstance();

    CRoomList* Roomlist;
    Roomlist=Roomlist->getInstance();

    int x=str.split(";")[0].toInt();
    qDebug()<<x;

    if(x==1)
       {
        qDebug()<<"x este 1";

        std::string username=str.split(";")[1].toStdString();
        std::string password=str.split(";")[2].toStdString();
        bool ok = DataBase->verifyLogin(username,password);
        if(ok==0){
            qDebug() <<"Cont invalid";
            message="1;";
        }
        else if(ok==1){
             qDebug() <<"Cont valid";
             message="3;1;";
    }}
    if(x==2){
        qDebug()<<"x este 2";
        QString username=str.split(";")[1];
        QString password=str.split(";")[2];
        //qDebug()<<username.c_str();
        bool ok = DataBase->verifyUnregisteredUser(username,password);
        if(ok==0){
            qDebug() <<"Cont invalid";
            message="2;";
        }
        else if(ok==1){
             qDebug() <<"Cont valid";
            message="3;2";
        }
    }

    if(x==3){
      QString username=str.split(";")[1];
      int roomID = str.split(";")[1].toInt();
      QString option=str.split(";")[3];
        Roomlist->userVotes(roomID,username,option);
        message="4";
    }

    if(x==4){
        //see result
    }
}

const char* CClientHandler::getMessage()
{
    return message;
}
