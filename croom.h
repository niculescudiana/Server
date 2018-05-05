#ifndef CROOM_H
#define CROOM_H
#include<vector>
#include<iostream>
#include<string>
#include<map>
#include<QString>
#include<QStringList>

class CRoom
{
public:

int room_ID;
std::vector<std::string> option_list;
std::map<QString, int> options_and_votes;
std::string title;
QStringList allowed_users;

public:
CRoom();
~CRoom();
bool HasUser(std::string username); //{allowed_user.Contains(username.c_str());}
void UserVotes(std::string username, int option){} /*{
            allowed_users.erase(username);
            auto it = options_and_votes.find(option);
            it.value ++; }
*/
};

#endif // CROOM_H
