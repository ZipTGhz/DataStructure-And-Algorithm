#pragma once
#include "Document.cpp"
#include <vector>

class Folder
{
private:
    string name;
    vector<Document> myFolder;

public:
    Folder(){};
    Folder(string name) : name(name){};

    void addDocument(const Document &__document)
    {
        myFolder.push_back(__document);
    }

    Document &operator[](int i) { return myFolder[i]; }
    const Document &operator[](int i) const { return myFolder[i]; }

    int findDocument(const string &__name)
    {
        for (int i = 0; i < myFolder.size(); i++)
        {
            if (myFolder[i].getNameDocument() == __name)
            {
                return i;
            }
        }
        return -1;
    }

    void deleteDocument(const string &__name)
    {
        for (int i = 0; i < myFolder.size(); i++)
        {
            if (myFolder[i].getNameDocument() == __name)
            {
                myFolder.erase(myFolder.begin() + i);
                cout << "Xoa tai lieu thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay tai lieu!" << endl;
    }

    void showAllDocument() const
    {
        for (const Document &document : myFolder)
            cout << document.getNameDocument() << "." << document.getFormatDocument() << endl;
        cout << endl;
    }

    string getNameFolder() const
    {
        return name;
    }

    bool isEmpty()
    {
        return myFolder.empty();
    }
};