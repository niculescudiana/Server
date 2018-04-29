#ifndef CROOM_H
#define CROOM_H
#include<vector>
#include<iostream>
#include<string>
#include<map>

class CRoom
{
private:

int room_ID;
std::vector<std::string> option_list_;
std::map<int, int> options_and_votes_;
std::string title;
std::string description;
std::vector<std::string> allowed_users;

public:
CRoom();
~CRoom();
//bool HasUser(std::string username) {allowed_users.Contains(username.c_str());}
//void UserVotes(std::string username, int option) {
//            allowed_users.remove(username);
//            auto it = options_and_votes.Find( option); it.Value ++; }
//
};

#endif // CROOM_H
