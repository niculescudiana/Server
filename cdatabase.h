#ifndef CDATABASE_H
#define CDATABASE_H
#include<QtXml>
#include<QtCore>
#include<QDebug>
#include<list>
#include<iostream>

class CDataBase
{
private:
    QDomDocument accounts;
    std::list <std::string> unregistered_accounts;
    CDataBase();
    ~CDataBase();
     static CDataBase *mp_Instance;

public:
    static CDataBase* getInstance();
    void addUser(std::string username, std::string password){}
    void setDataBase();
};

#endif // CDATABASE_H
