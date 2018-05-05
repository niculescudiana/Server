#include "croomlist.h"
#include<QFile>
#include<QTextStream>
#include<QString>
#include<QStringList>

CRoomList::CRoomList(){}
CRoomList::~CRoomList(){}

//CRoomList::GetPollById(int room_Id){}
//CRoomList::HasUser(char username){}


CRoomList* CRoomList::mp_Instance = nullptr;

CRoomList* CRoomList::getInstance() {

return (!mp_Instance) ?
    mp_Instance = new CRoomList:
    mp_Instance;
}

void CRoomList::createRoom(int room_Id)
{
    CRoom* Room=new CRoom();
    QFile file;

    if(room_Id==1)
        file.setFileName("room1.txt");
    else if(room_Id==2)
        file.setFileName("room2.txt");
    else if(room_Id==3)
        file.setFileName("room3.txt");


    if(!file.open(QIODevice::ReadOnly))
        return;
    Room->room_ID=room_Id;

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString title=in.readLine();
        Room->title=title.toStdString();

        QString options=in.readLine();
        QStringList optionlist=options.split(" ");
        for(int i=0; i<optionlist.size(); i++)
            Room->options_and_votes[optionlist[i]]=0;
        QString users=in.readLine();
        QStringList userlist= users.split(" ");
            Room->allowed_users = userlist;
    }

}
