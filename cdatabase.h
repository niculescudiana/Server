#ifndef CDATABASE_H
#define CDATABASE_H
#include<QtXml>
#include<QtCore>
#include<QDebug>
#include<list>
#include<iostream>
#include<QList>

class CDataBase
{
private:
    //QDomDocument accounts;
    QList <QString> unregistered_accounts;
    CDataBase();
    ~CDataBase();
     static CDataBase *mp_Instance;

public:
    static CDataBase* getInstance();
    void addUser(std::string username, std::string password);
    bool verifyLogin(std::string username, std::string password);
    bool verifyUnregisteredUser(QString username,QString password);
    void setDataBaseRegistered();
    void setDataBaseUnregistered();
};

#endif // CDATABASE_H
