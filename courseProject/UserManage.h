#pragma once
#include <fstream>
using std::string;

#define FILE_PATH "../data/users.txt"

struct User {
    size_t id;
    string username;
    string password;
    bool isAdmin;
};

bool LoginUser(const string&, const string&, User&);
bool UserExists(const string&);
int GetNextUserID();
bool RegisterUser(const string&, const string&, const bool&);