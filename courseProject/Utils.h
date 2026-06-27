#pragma once
#include <string>
#include <map>

using System::String;
using System::Collections::Generic::Dictionary;


inline std::string ToStdString(String^ str) {
    using System::IntPtr;
    using System::Runtime::InteropServices::Marshal;

    IntPtr ptr = Marshal::StringToHGlobalAnsi(str);
    std::string result = static_cast<char*>(ptr.ToPointer());
    Marshal::FreeHGlobal(ptr);

    return result;
}

inline String^ ToSysString(const std::string& str) {
    return gcnew String(str.c_str());
}



public enum class Lang {
    RU,
    EN,
    BY
};

public enum class Theme {
    White,
    Blue,
    Purple
};


inline std::string LangToString(Lang lang) {
    switch (lang) {
    case Lang::RU: return "RU";
    case Lang::EN: return "EN";
    case Lang::BY: return "BY";
    default: return "RU";
    }
}

inline Lang StringToLang(const std::string& str) {
    if (str == "RU") return Lang::RU;
    if (str == "EN") return Lang::EN;
    if (str == "BY") return Lang::BY;

    return Lang::RU;
}


inline std::string ThemeToString(Theme theme) {
    switch (theme) {
    case Theme::White: return "White";
    case Theme::Blue: return "Blue";
    case Theme::Purple: return "Purple";
    default: return "RU";
    }
}

inline Theme StringToTheme(const std::string& str) {
    if (str == "White") return Theme::White;
    if (str == "Blue") return Theme::Blue;
    if (str == "Purple") return Theme::Purple;

    return Theme::White;
}


public ref class GlobalSettings abstract sealed {
public:
    // текущий язык и тема
    static Lang CurrentLang = Lang::RU;
    static Theme CurrentTheme = Theme::White;

private:
    // словари
    static Dictionary<String^, String^>^ RU = CreateRU();
    static Dictionary<String^, String^>^ EN = CreateEN();
    static Dictionary<String^, String^>^ BY = CreateBY();


public:
    static String^ GetLang(String^ key) {
        switch (CurrentLang) {
            case Lang::RU: return RU[key];
            case Lang::EN: return EN[key];
            case Lang::BY: return BY[key];
        }

        return key;
    }

    //static Color GetThemeT() {
    //    switch (CurrentTheme) {
    //        case Theme::White: return Color::White;
    //        case Theme::Blue: return Color::Blue;
    //        case Theme::Purple: return Color::Purple;
    //    }

    //    return Color::White;
    //}

private:
    static Dictionary<String^, String^>^ CreateRU() {
        auto dict = gcnew Dictionary<String^, String^>;

        dict->Add("NameLabel", "Название:"),
        dict->Add("InpName", "Введите название:"),
        dict->Add("CostLabel", "Стоимость:"),
        dict->Add("InpCost", "Введите стоимость:");
        dict->Add("AddNodeBtn", "Добавить узел");
        dict->Add("CreateTreeBtn", "Создать дерево");

        dict->Add("PrintCost", "Стоимость филиала");
        dict->Add("groupBox", "Взаимодействия с филиалом");
        dict->Add("CalcSumBtn", "Вычислить стоимость");
        dict->Add("DeleteNodeBtn", "Удалить узел");
        dict->Add("RebuildTreeBtn", "Перестроить дерево");
        dict->Add("DeleteTreeBtn", "Удалить дерево");

        dict->Add("MainMenuItem", "Главная");
        dict->Add("SaveChangesMenuItem", "Сохранить изменения");
        dict->Add("RebuildTreeMenuItem", "Перестроить дерево");
        dict->Add("DeleteTreeMenuItem", "Удалить дерево");
        dict->Add("LogOutMenuItem", "Выйти из системы");
        dict->Add("ViewMenuItem", "Вид");
        dict->Add("LanguageMenuItem", "Язык");
        dict->Add("LangRUMenuItem", "Русский");
        dict->Add("LangENMenuItem", "Английский");
        dict->Add("LangBYMenuItem", "Белорусский");
        dict->Add("ThemeMenuItem", "Тема");
        dict->Add("WhiteMenuItem", "Белый");
        dict->Add("BlueMenuItem", "Синий");
        dict->Add("PurpleMenuItem", "Фиолетовый");
        dict->Add("HelpMenuItem", "Справка");

        dict->Add("SelectionError", "Выберите филиал.");
        dict->Add("ExistingTreeError", "Удалите существующее дерево.");
        dict->Add("EmptyFieldsError", "Заполните поля.");

        dict->Add("WelcomeStr", "Добро пожаловать ");
        dict->Add("SelectedMode", " (Гостевой режим)");


        dict->Add("LogInHeader", "Вход в систему");
        dict->Add("RegistrationHeader", "Регистрация");

        dict->Add("UsernameLabel", "Имя пользователя:");
        dict->Add("UsernameInp", "Введите имя:");
        dict->Add("PasswordLabel", "Пароль:");
        dict->Add("PasswordInp", "Введите пароль:");
        dict->Add("PasswordConfLabel", "Подтвердить пароль:");
        dict->Add("PasswordConfInp", "Подтвердите пароль:");
        dict->Add("LogInBtn", "Вход");
        dict->Add("ToRegisterBtn", "Зарегистрироваться");
        dict->Add("IsAdminBox", "Админ?");
        dict->Add("RegistrationBtn", "Создать аккаунт");
        dict->Add("BackToLogBtn", "Назад");


        return dict;
    }

    static Dictionary<String^, String^>^ CreateEN() {
        auto dict = gcnew Dictionary<String^, String^>;

        dict->Add("NameLabel", "Name:");
        dict->Add("InpName", "Enter name:");
        dict->Add("CostLabel", "Cost:");
        dict->Add("InpCost", "Enter cost:");
        dict->Add("AddNodeBtn", "Add node");
        dict->Add("CreateTreeBtn", "Create tree");

        dict->Add("PrintCost", "Branch cost");
        dict->Add("groupBox", "Branch interactions");
        dict->Add("CalcSumBtn", "Calculate cost");
        dict->Add("DeleteNodeBtn", "Delete node");
        dict->Add("RebuildTreeBtn", "Rebuild tree");
        dict->Add("DeleteTreeBtn", "Delete tree");

        dict->Add("MainMenuItem", "Main");
        dict->Add("SaveChangesMenuItem", "Save changes");
        dict->Add("RebuildTreeMenuItem", "Rebuild tree");
        dict->Add("DeleteTreeMenuItem", "Delete tree");
        dict->Add("LogOutMenuItem", "Log out");
        dict->Add("ViewMenuItem", "View");
        dict->Add("LanguageMenuItem", "Language");
        dict->Add("LangRUMenuItem", "Russian");
        dict->Add("LangENMenuItem", "English");
        dict->Add("LangBYMenuItem", "Belarusian");
        dict->Add("ThemeMenuItem", "Theme");
        dict->Add("WhiteMenuItem", "White");
        dict->Add("BlueMenuItem", "Blue");
        dict->Add("PurpleMenuItem", "Purple");
        dict->Add("HelpMenuItem", "Help");

        dict->Add("SelectionError", "Select a branch.");
        dict->Add("ExistingTreeError", "Delete the existing tree.");
        dict->Add("EmptyFieldsError", "Fill in the fields.");

        dict->Add("WelcomeStr", "Welcome ");
        dict->Add("SelectedMode", " (Guest mode)");


        dict->Add("LogInHeader", "Log in");
        dict->Add("RegistrationHeader", "Registration");

        dict->Add("UsernameLabel", "Username:");
        dict->Add("UsernameInp", "Enter username:");
        dict->Add("PasswordLabel", "Password:");
        dict->Add("PasswordInp", "Enter password:");
        dict->Add("PasswordConfLabel", "Confirm password:");
        dict->Add("PasswordConfInp", "Confirm password:");
        dict->Add("LogInBtn", "Log in");
        dict->Add("ToRegisterBtn", "Sign up");
        dict->Add("IsAdminBox", "Admin?");
        dict->Add("RegistrationBtn", "Create account");
        dict->Add("BackToLogBtn", "Back");

        return dict;
    }

    static Dictionary<String^, String^>^ CreateBY() {
        auto dict = gcnew Dictionary<String^, String^>;

        dict->Add("NameLabel", "Назва:");
        dict->Add("InpName", "Увядзіце назву:");
        dict->Add("CostLabel", "Кошт:");
        dict->Add("InpCost", "Увядзіце кошт:");
        dict->Add("AddNodeBtn", "Дадаць вузел");
        dict->Add("CreateTreeBtn", "Стварыць дрэва");

        dict->Add("PrintCost", "Кошт філіяла");
        dict->Add("groupBox", "Узаемадзеянне з філіялам");
        dict->Add("CalcSumBtn", "Вылічыць кошт");
        dict->Add("DeleteNodeBtn", "Выдаліць вузел");
        dict->Add("RebuildTreeBtn", "Перабудаваць дрэва");
        dict->Add("DeleteTreeBtn", "Выдаліць дрэва");

        dict->Add("MainMenuItem", "Галоўная");
        dict->Add("SaveChangesMenuItem", "Захаваць змены");
        dict->Add("RebuildTreeMenuItem", "Перабудаваць дрэва");
        dict->Add("DeleteTreeMenuItem", "Выдаліць дрэва");
        dict->Add("LogOutMenuItem", "Выйсці з сістэмы");
        dict->Add("ViewMenuItem", "Выгляд");
        dict->Add("LanguageMenuItem", "Мова");
        dict->Add("LangRUMenuItem", "Руская");
        dict->Add("LangENMenuItem", "Англійская");
        dict->Add("LangBYMenuItem", "Беларуская");
        dict->Add("ThemeMenuItem", "Тэма");
        dict->Add("WhiteMenuItem", "Белая");
        dict->Add("BlueMenuItem", "Сіняя");
        dict->Add("PurpleMenuItem", "Фіялетавая");
        dict->Add("HelpMenuItem", "Даведка");

        dict->Add("SelectionError", "Выберыце філіял.");
        dict->Add("ExistingTreeError", "Выдаліце існуючае дрэва.");
        dict->Add("EmptyFieldsError", "Запоўніце палі.");

        dict->Add("WelcomeStr", "Сардэчна запрашаем ");
        dict->Add("SelectedMode", " (Гасцявы рэжым)");


        dict->Add("LogInHeader", "Уваход у сістэму");
        dict->Add("RegistrationHeader", "Рэгістрацыя");

        dict->Add("UsernameLabel", "Імя карыстальніка:");
        dict->Add("UsernameInp", "Увядзіце імя:");
        dict->Add("PasswordLabel", "Пароль:");
        dict->Add("PasswordInp", "Увядзіце пароль:");
        dict->Add("PasswordConfLabel", "Пацвердзіце пароль:");
        dict->Add("PasswordConfInp", "Пацвердзіце пароль:");
        dict->Add("LogInBtn", "Увайсці");
        dict->Add("ToRegisterBtn", "Зарэгістравацца");
        dict->Add("IsAdminBox", "Адміністратар?");
        dict->Add("RegistrationBtn", "Стварыць акаўнт");
        dict->Add("BackToLogBtn", "Назад");

        return dict;
    }
};