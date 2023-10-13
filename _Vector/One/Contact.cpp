#pragma once
#include <iostream>
#include <string>

#define endl "\n"

using namespace std;

class Contact
{
private:
    string fullName;
    string phoneNumber;
    string emailAddress;

public:
    Contact(){};
    Contact(string fullName, string phoneNumber, string emailAddress)
    {
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        this->emailAddress = emailAddress;
    }

    void newContact()
    {
        fflush(stdin);
        cout << "Nhap ho va ten: ";
        getline(cin, fullName);
        cout << "Nhap so dien thoai: ";
        getline(cin, phoneNumber);
        cout << "Nhap dia chi email: ";
        getline(cin, emailAddress);
    }

    void showContact()
    {
        cout << "Ho va ten: " << fullName << endl;
        cout << "So dien thoai: " << phoneNumber << endl;
        cout << "Dia chi email: " << emailAddress << endl;
    }

    string getPhoneNumber()
    {
        return phoneNumber;
    }
};