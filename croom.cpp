#include "croom.h"

CRoom::CRoom(){}

CRoom::~CRoom(){}

bool CRoom::HasUser(std::string username)
{
    for(int i=0;i< allowed_users.size();i++)
        if(allowed_users[i].toStdString()==username)
            return true;
    return false;
}
