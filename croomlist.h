#ifndef CROOMLIST_H
#define CROOMLIST_H
#include"croom.h"
#include <list>
#include<iostream>
#include<string>
#include<QString>

//using namespace std;

class CRoomList
{
private:
    CRoomList();
    ~CRoomList();
    static CRoomList* mp_Instance;
    static int number_of_rooms;
protected:
    CRoom** RoomList;
public:
    static CRoomList* getInstance();
    bool HasUser(int room_Id, QString username);
    //CRoom& GetRoomById(int room_Id);
    void userVotes(int room_id, QString username, QString option);
    void createRoom(int room_Id);
    QString displayWinner(int room_Id);

};

#endif // CROOMLIST_H
