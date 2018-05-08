#include "croomlist.h"
#include<QFile>
#include<QTextStream>
#include<QString>
#include<QStringList>
#include<QDebug>
#include<QPair>

CRoomList::CRoomList(){

        RoomList=new CRoom*[4];
          for(int i=0;i<4;i++)
              RoomList[i]=0;
}
CRoomList::~CRoomList(){}


CRoomList* CRoomList::mp_Instance = nullptr;
int CRoomList::number_of_rooms=0;

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
            Room->options_and_votes.insert(optionlist[i],0);

        QString users=in.readLine();
        QStringList userlist= users.split(" ");
            Room->allowed_users = userlist;
    }

    RoomList[number_of_rooms]=Room;
    number_of_rooms++;

}

/*CRoom& CRoomList::GetRoomById(int room_Id)
{
    /*std::list<CRoom*>::iterator it;
    for(it=RoomList.begin(); it!=RoomList.end(); ++it)
    {
        CRoom* mRoom=*it;
        if( mRoom->room_ID== room_Id)
            return *it;
    }
    return nullptr;
    for(int i=0;i>number_of_rooms;i++)
        if(RoomList[i]->room_ID==room_Id)
            return &RoomList[i];
    return nullptr;


}
*/
bool CRoomList::HasUser(int room_Id, QString username)
{
    for(int i=0;i<number_of_rooms;i++)
        if(RoomList[i]->room_ID==room_Id)
        {
            QMutableListIterator<QString> iter(RoomList[i]->allowed_users);
            while(iter.hasNext())
            {
               if(iter.next()==username){

                   qDebug()<<"user is allowed";
                   return 1;

                     }
             }
        }
    return 0;
}
void CRoomList::userVotes(int room_id, QString username, QString option)
{
    for(int i=0;i>number_of_rooms;i++)
        if(RoomList[i]->room_ID==room_id)
        {
            QMutableListIterator<QString> iter(RoomList[i]->allowed_users);
            while(iter.hasNext())
            {
               if(iter.next()==username){
                   iter.remove();
                   qDebug()<<"removed from allowed users";

                     }
             }

            RoomList[i]->options_and_votes.last()++;
         }
}

QString CRoomList::displayWinner(int room_Id)
{
    QString winner;
    int max_votes=0;
    for(int i=0;i>number_of_rooms;i++)
        if(RoomList[i]->room_ID==room_Id)
        {
            for (QMap<QString,int>::iterator it= RoomList[i]->options_and_votes.begin(); it!= RoomList[i]->options_and_votes.end(); ++it)
                if(it.value() > max_votes)
                       { max_votes= it.value() ; winner=it.key();}

        }
    return winner;
}
