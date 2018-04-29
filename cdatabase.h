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

public:
    CDataBase();
    ~CDataBase();
    void addUser(std::string username, std::string password){}
};

#endif // CDATABASE_H
