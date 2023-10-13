#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

time_t now = time(0);
tm *ltm = localtime(&now);

class Document
{
private:
    string name;
    string description;
    string author;
    string format;
    int yearOfPublication;

public:
    Document(){};
    Document(string name, string description, string author, string format, int yearOfPublication)
    {
        this->name = name;
        this->description = description;
        this->author = author;
        this->format = format;
        this->yearOfPublication = yearOfPublication;
    }

    void createDocumentInfo()
    {
        fflush(stdin);
        cout << "Nhap ten tai lieu: ";
        getline(cin, name);
        cout << "Nhap mo ta cua tai lieu: ";
        getline(cin, description);
        cout << "Nhap ten tac gia: ";
        getline(cin, author);
        cout << "Nhap dinh dang cua tai lieu: ";
        getline(cin, format);
        do
        {
            cout << "Nhap nam xuat ban: ";
            cin >> yearOfPublication;
        } while (yearOfPublication < 0 || yearOfPublication > 1900 + ltm->tm_year);
    }

    void displayDocumentInfo() const
    {
        cout << "Ten tai lieu: " << name << endl;
        cout << "Mo ta cua tai lieu: " << description << endl;
        cout << "Ten tac gia: " << author << endl;
        cout << "Dinh dang cua tai lieu: " << format << endl;
        cout << "Nam xuat ban: " << yearOfPublication << endl;
    }

    string getNameDocument() const
    {
        return name;
    }

    string getFormatDocument() const
    {
        return format;
    }
};