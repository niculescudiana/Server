#ifndef CROOMLIST_H
#define CROOMLIST_H
#include"croom.h"
#include <list>
#include<iostream>
#include<string>
//using namespace std;

class CRoomList
{
protected:
    std::list <CRoom*> RoomList;
public:

    CRoomList();
    ~CRoomList();
    std::string HasUser(char username);
    CRoom& GetRoomById(int room_Id);

};

#endif // CROOMLIST_H
