#include "UserManage.h"

// Работа с users.txt
bool LoginUser(const string& username, const string& password, User* result) {
    std::ifstream file(USER_FILE_PATH);

    if (!file) {
        return false;
    }

    int id;
    string name, pass, lang, theme;
    int admin;


    while (file >> id >> name >> pass >> admin >> lang >> theme) {
        if (name == username && pass == password) {
            result->id = id;
            result->username = name;
            result->password = pass;
            result->isAdmin = admin;
            result->language = StringToLang(lang);
            result->theme = StringToTheme(theme);

            return true;
        }
    }

    return false;
}

bool UserExists(const string& username) {
    std::ifstream file(USER_FILE_PATH);

    int id;
    string name, pass, lang, theme;
    int admin;

    while (file >> id >> name >> pass >> admin >> lang >> theme) {
        if (name == username) {
            return true;
        }
    }

    return false;
}

int GetNextUserID() {
    std::ifstream file(USER_FILE_PATH);

    int id, maxId = 0;
    string name, pass, lang, theme;
    int admin;

    while (file >> id >> name >> pass >> admin >> lang >> theme)
    {
        if (id > maxId)
            maxId = id;
    }

    return maxId + 1;
}

int RegisterUser(const string& username, const string& password, const bool& isAdmin) {
    if (UserExists(username)) {
        return 0;
    }

    int id = GetNextUserID();

    std::ofstream file(USER_FILE_PATH, std::ios::app);

    if (!file) {
        throw std::runtime_error("Файл не открыт");
    }

    file << id << " "
        << username << " "
        << password << " "
        << isAdmin  << " "
        << LangToString(GlobalSettings::CurrentLang) << " "
        << ThemeToString(GlobalSettings::CurrentTheme) << std::endl;

    return id;
}

void UpdateUserSettings(int user_id) {
    std::ifstream in(USER_FILE_PATH);
    std::ofstream out(TEMPU_FILE_PATH);

    int id, isAdmin;
    string login, pass;
    string langStr, themeStr;

    while (in >> id >> login >> pass >> isAdmin >> langStr >> themeStr) {
        if (id == user_id) {
            langStr = LangToString(GlobalSettings::CurrentLang);
            themeStr = ThemeToString(GlobalSettings::CurrentTheme);
        }

        out << id << " "
            << login << " "
            << pass << " "
            << isAdmin << " "
            << langStr << " "
            << themeStr << std::endl;
    }

    in.close();
    out.close();

    remove(USER_FILE_PATH);
    rename(TEMPU_FILE_PATH, USER_FILE_PATH);
}



// Работа с trees.dat
// Сохранение дерева
void save_tree_stream(My_TreeNode* node, std::ostream& out) {
    if (!node) {
        out << "# ";
        return;
    }

    out << node->data_field.bankName << " "
        << node->data_field.cost << " ";

    save_tree_stream(node->left, out);
    save_tree_stream(node->right, out);
}

void save_tree_file(int user_id, BinaryTree* tree) {
    std::ostringstream buffer;

    save_tree_stream(tree->get_root(), buffer);

    string data = buffer.str();
    size_t size = data.size();

    std::ofstream file(TREE_FILE_PATH, std::ios::binary | std::ios::app);

    if (!file) {
        throw std::runtime_error("Ошибка открытия trees.dat");
    }

    // ID пользователя
    file.write((char*)&user_id, sizeof(user_id));

    // размер блока
    file.write((char*)&size, sizeof(size));

    // само дерево
    file.write(data.c_str(), size);

    file.close();
}


// Загрузка дерева
My_TreeNode* load_tree_stream(std::istream& in, BinaryTree* tree) {
    string name;
    in >> name;

    if (name == "#") {
        return nullptr;
    }

    int cost;
    in >> cost;

    DataField data;
    data.bankName = name;
    data.cost = cost;

    My_TreeNode* node = tree->create_node(data);

    node->left = load_tree_stream(in, tree);
    node->right = load_tree_stream(in, tree);

    return node;
}

bool load_tree_file(int user_id, BinaryTree* tree) {
    std::ifstream file(TREE_FILE_PATH, std::ios::binary);

    if (!file) {
        return false;
    }

    while (file) {
        int id;
        size_t size;

        // читаем ID
        file.read((char*)&id, sizeof(id));
        if (file.eof()) {
            break;
        }

        // читаем размер
        file.read((char*)&size, sizeof(size));

        if (id == user_id) {
            string data(size, '\0');
            file.read(&data[0], size);

            std::istringstream in(data);

            // Создание корня
            string name;
            in >> name;

            if (name == "#") {
                return nullptr;
            }

            int cost;
            in >> cost;

            DataField dataF;
            dataF.bankName = name;
            dataF.cost = cost;

            tree->create_tree(dataF);

            tree->get_root()->left = load_tree_stream(in, tree);
            tree->get_root()->right = load_tree_stream(in, tree);

            return true;
        }
        else {
            file.seekg(size, std::ios::cur);
        }
    }

    return false;
}


// Удаление
void delete_tree_file(int id_del) {
    std::ifstream in(TREE_FILE_PATH, std::ios::binary);
    std::ofstream out(TEMPT_FILE_PATH, std::ios::binary);

    if (!in || !out) {
        return;
    }

    while (in) {
        int id;
        size_t size;

        in.read((char*)&id, sizeof(id));
        if (!in) {
            break;
        }

        in.read((char*)&size, sizeof(size));

        string data(size, '\0');
        in.read(&data[0], size);

        if (id != id_del) {
            out.write((char*)&id, sizeof(id));
            out.write((char*)&size, sizeof(size));
            out.write(data.c_str(), size);
        }
    }

    in.close();
    out.close();

    remove(TREE_FILE_PATH);
    rename(TEMPT_FILE_PATH, TREE_FILE_PATH);
}


// Перезапись
void update_tree_file(int user_id, BinaryTree* tree) {
    delete_tree_file(user_id);
    save_tree_file(user_id, tree);
}