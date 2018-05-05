#ifndef CROOMLIST_H
#define CROOMLIST_H
#include"croom.h"
#include <list>
#include<iostream>
#include<string>
//using namespace std;

class CRoomList
{
private:
    CRoomList();
    ~CRoomList();
    static CRoomList* mp_Instance;
protected:
    std::list <CRoom*> RoomList;
public:
    static CRoomList* getInstance();
    std::string HasUser(char username){}
    CRoom& GetRoomById(int room_Id){}
    void createRoom(int room_Id);

};

#endif // CROOMLIST_H
