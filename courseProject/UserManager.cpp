#include "UserManage.h"

bool LoginUser(const string& username, const string& password, User& result) {
    std::ifstream file(FILE_PATH);

    if (!file) {
        return false;
    }

    int id;
    string name, pass;
    int admin;

    while (file >> id >> name >> pass >> admin) {
        if (name == username && pass == password) {
            result.id = id;
            result.username = name;
            result.password = pass;
            result.isAdmin = admin;

            return true;
        }
    }

    return false;
}

bool UserExists(const string& username) {
    std::ifstream file(FILE_PATH);

    int id;
    string name, pass;
    int admin;

    while (file >> id >> name >> pass >> admin) {
        if (name == username) {
            return true;
        }
    }

    return false;
}

int GetNextUserID() {
    std::ifstream file(FILE_PATH);

    int id, maxId = 0;
    string name, pass;
    int admin;

    while (file >> id >> name >> pass >> admin)
    {
        if (id > maxId)
            maxId = id;
    }

    return maxId + 1;
}

bool RegisterUser(const string& username, const string& password, const bool& isAdmin) {
    if (UserExists(username)) {
        return false;
    }

    int id = GetNextUserID();

    std::ofstream file(FILE_PATH, std::ios::app);

    if (!file) {
        throw std::runtime_error("Файл не открыт");
    }

    file << id << " "
        << username << " "
        << password << " "
        << isAdmin << std::endl;

    return true;
}