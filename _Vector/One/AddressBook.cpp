#pragma once
#include <vector>
#include "Contact.cpp"

class AddressBook
{
private:
    vector<Contact> myAddressBook;

public:
    void addContact(const Contact &__newContact)
    {
        myAddressBook.push_back(__newContact);
    }

    void addContact(const string &fullName, const string &phoneNumber, const string &emailAddress)
    {
        myAddressBook.push_back(Contact(fullName, phoneNumber, emailAddress));
    }

    void deleteContactByPhoneNumber(const string &__phoneNumber)
    {
        for (int i = 0; i < myAddressBook.size(); i++)
        {
            if (myAddressBook[i].getPhoneNumber() == __phoneNumber)
            {
                myAddressBook.erase(myAddressBook.begin() + i);
                cout << "Xoa lien he thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay thong tin lien he co SDT tuong ung!" << endl;
    }

    void findContactByPhoneNumber(const string &__phoneNumber)
    {
        for (int i = 0; i < myAddressBook.size(); i++)
        {
            if (myAddressBook[i].getPhoneNumber() == __phoneNumber)
            {
                myAddressBook[i].showContact();
                return;
            }
        }
        cout << "Khong tim thay thong tin lien he co SDT tuong ung!" << endl;
    }

    void showAllContact()
    {
        if (myAddressBook.empty())
        {
            cout << "Danh ba trong!" << endl;
            return;
        }
        for (int i = 0; i < myAddressBook.size(); i++)
        {
            cout << "Thong tin lien he thu " << i + 1 << ":" << endl;
            myAddressBook[i].showContact();
        }
    }
};

// int main()
// {
//     Contact temp;
//     AddressBook arr;
//     temp.newContact();
//     arr.addContact(temp);
//     temp.newContact();
//     arr.addContact(temp);
//     arr.showAllContact();
//     return 0;
// }