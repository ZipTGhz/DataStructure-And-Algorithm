#pragma once
#include "Folder.cpp"

class User
{
private:
    string name = "";
    vector<Folder> myUser;

public:
    User(){};
    User(string name) : name(name){};

    Folder &operator[](int i) { return myUser[i]; }
    const Folder &operator[](int i) const { return myUser[i]; }

    void addFolder(const Folder &__folder)
    {
        myUser.push_back(__folder);
    }

    int findFolder(const string &__name)
    {
        for (int i = 0; i < myUser.size(); i++)
        {
            if (myUser[i].getNameFolder() == __name)
            {
                return i;
            }
        }
        return -1;
    }

    void deleteFolder(const string &__name)
    {
        for (int i = 0; i < myUser.size(); i++)
        {
            if (myUser[i].getNameFolder() == __name)
            {
                myUser.erase(myUser.begin() + i);
                cout << "Xoa thu muc thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay thu muc!" << endl;
    }

    void showAllFolder()
    {
        for (const Folder &folder : myUser)
            cout << ".\\" << folder.getNameFolder() << endl;
        cout << endl;
    }

    void setUserName(const string &name)
    {
        this->name = name;
    }

    string getUserName()
    {
        return name;
    }

    bool isEmpty()
    {
        return myUser.empty();
    }
};
