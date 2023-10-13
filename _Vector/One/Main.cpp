#include "AddressBook.cpp"
#include <unistd.h>
#include <stdlib.h>

int mode;
AddressBook myAddressBook;

void home();
void addContactToAddressBook();
void deleteContactFromAddressBook();
void findContactFromAddressBook();
void chooseMode(const int &);
void returnMenu();

int main()
{
    system("cls");
    home();
    cout << endl;

    do
    {
        cout << "Lua chon cua ban: ";
        cin >> mode;
    } while (mode < 0 || mode > 5);
    chooseMode(mode);

    return 0;
}

void home()
{
    cout << "|***************SO DANH BA****************|" << endl;
    cout << endl;
    cout << "|    1. Them lien he moi                  |" << endl;
    cout << endl;
    cout << "|    2. Xoa lien he                       |" << endl;
    cout << endl;
    cout << "|    3. Tim kiem lien he                  |" << endl;
    cout << endl;
    cout << "|    4. Hien thi danh sach cac lien he    |" << endl;
    cout << endl;
    cout << "|    5. Thoat chuong trinh                |" << endl;
    cout << endl;
    cout << "|*****************************************|" << endl;
}

void addContactToAddressBook()
{
    Contact __temp;
    __temp.newContact();
    myAddressBook.addContact(__temp);
    cout << "Nhap thong tin thanh cong!" << endl;
}

void deleteContactFromAddressBook()
{
    string __phoneNumber;
    cout << "Nhap so dien thoai can xoa: ";
    fflush(stdin);
    getline(cin, __phoneNumber);
    myAddressBook.deleteContactByPhoneNumber(__phoneNumber);
}

void findContactFromAddressBook()
{
    string __phoneNumber;
    cout << "Nhap so dien thoai can tim: ";
    fflush(stdin);
    getline(cin, __phoneNumber);
    myAddressBook.findContactByPhoneNumber(__phoneNumber);
}

void chooseMode(const int &__mode)
{
    if (__mode == 1)
    {
        addContactToAddressBook();
        returnMenu();
    }
    else if (__mode == 2)
    {
        deleteContactFromAddressBook();
        returnMenu();
    }
    else if (__mode == 3)
    {
        findContactFromAddressBook();
        returnMenu();
    }
    else if (__mode == 4)
    {
        myAddressBook.showAllContact();
        returnMenu();
    }
    else
    {
        cout << "Dang thoat chuong trinh..." << endl;
        exit(0);
    }
}

void returnMenu()
{
    fflush(stdin);
    cout << "An nut bat ky de tro ve man hinh chinh" << endl;
    getchar();
    system("cls");
    main();
}
