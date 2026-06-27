#pragma once
#include <fstream>
#include <sstream>
#include "Utils.h"
#include "BinaryTree.h"

using std::string;

#define USER_FILE_PATH "./users.txt"
#define TREE_FILE_PATH "./trees.dat"
#define TEMPU_FILE_PATH "./temp.txt"
#define TEMPT_FILE_PATH "./temp.dat"

struct User {
    size_t id;
    string username;
    string password;
    bool isAdmin;
    Lang language = Lang::RU;
    Theme theme = Theme::White;
};

bool LoginUser(const string&, const string&, User*);
bool UserExists(const string&);
int GetNextUserID();
int RegisterUser(const string&, const string&, const bool&);
void UpdateUserSettings(int user_id);

void save_tree_stream(My_TreeNode*, std::ostream&);
void save_tree_file(int user_id, BinaryTree* tree);
My_TreeNode* load_tree_stream(std::istream&, BinaryTree*);
bool load_tree_file(int user_id, BinaryTree* tree);
void delete_tree_file(int);
void update_tree_file(int user_id, BinaryTree* tree);