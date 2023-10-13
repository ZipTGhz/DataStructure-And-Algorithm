#include "User.cpp"

int mode;

User newUser;

int createUserName = []
{
    system("cls");
    string name;
    cout << "Nhap ten nguoi dung: ";
    getline(cin, name);
    newUser.setUserName(name);
    return 0;
}();

void home();
void chooseMode(const int &__mode);

void addDocumentToFolder();
void deleteDocumentFromFolder();
void showAllDocumentFromFolder();

void addFolderToUser();
void deleteFolderFromUser();

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
    } while (mode < 0 || mode > 7);
    chooseMode(mode);

    return 0;
}

void home()
{
    int length = (63 - newUser.getUserName().length() - 9) >> 1;
    for (int i = 0; i < length; i++)
        cout << "*";
    cout << "XIN CHAO " << newUser.getUserName();
    for (int i = 0; i < length; i++)
        cout << "*";
    cout << (newUser.getUserName().length() & 1 ? "*" : "");
    cout << endl;
    // cout << "********************"
    //      << "XIN CHAO " << newUser.getUserName() << "********************" << endl;
    // cout << "------------------------------------------------------" << endl;
    cout << "|    1. Them tai lieu moi vao thu muc chi dinh                |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|    2. Xoa tai lieu khoi thu muc chi dinh                    |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|    3. Hien thi danh sach tai lieu trong thu muc chi dinh    |" << endl;
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "|    4. Them thu muc moi vao danh sach thu muc                |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|    5. Xoa thuc muc khoi danh sach thu muc                   |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|    6. Hien thi danh sach thu muc                            |" << endl;
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "|    7. Thoat chuong trinh                                    |" << endl;
    cout << "***************************************************************" << endl;
}

void chooseMode(const int &__mode)
{
    if (__mode == 1)
    {
        addDocumentToFolder();
        returnMenu();
    }
    else if (__mode == 2)
    {
        deleteDocumentFromFolder();
        returnMenu();
    }
    else if (__mode == 3)
    {
        showAllDocumentFromFolder();
        returnMenu();
    }
    else if (__mode == 4)
    {
        addFolderToUser();
        returnMenu();
    }
    else if (__mode == 5)
    {
        deleteFolderFromUser();
        returnMenu();
    }
    else if (__mode == 6)
    {
        if (newUser.isEmpty())
            cout << "Chua tao thu muc nao trong thu muc cua nguoi dung." << endl;
        else
            newUser.showAllFolder();
        returnMenu();
    }
    else
    {
        cout << "Dang thoat chuong trinh..." << endl;
        exit(0);
    }
}

void addDocumentToFolder()
{
    if (newUser.isEmpty())
    {
        cout << "Chua tao thu muc nao trong thu muc cua nguoi dung." << endl;
        return;
    }
    newUser.showAllFolder();
    string __folderName;
    fflush(stdin);
    cout << "Chon thu muc muon luu tru: ";
    getline(cin, __folderName);
    int idx = newUser.findFolder(__folderName);
    if (idx == -1)
    {
        cout << "Khong tim thay folder!" << endl;
        return;
    }
    Document __tempDocument;
    __tempDocument.createDocumentInfo();
    newUser[idx].addDocument(__tempDocument);
    cout << "Da them \"" << __tempDocument.getNameDocument() << "\" vao thu muc \"" << newUser[idx].getNameFolder() << "\"" << endl;
}

void deleteDocumentFromFolder()
{
    if (newUser.isEmpty())
    {
        cout << "Chua tao thu muc nao trong thu muc cua nguoi dung." << endl;
        return;
    }
    newUser.showAllFolder();
    string __folderName;
    fflush(stdin);
    cout << "Chon thu muc: ";
    getline(cin, __folderName);
    int idx = newUser.findFolder(__folderName);
    if (idx == -1)
    {
        cout << "Khong tim thay folder!" << endl;
        return;
    }
    if (newUser[idx].isEmpty())
    {
        cout << "Thu muc rong!" << endl;
        return;
    }
    string __tempDocumentName;
    fflush(stdin);
    cout << "Nhap ten tai lieu can xoa: ";
    getline(cin, __tempDocumentName);
    newUser[idx].deleteDocument(__tempDocumentName);
}

void showAllDocumentFromFolder()
{
    if (newUser.isEmpty())
    {
        cout << "Chua tao thu muc nao trong thu muc cua nguoi dung." << endl;
        return;
    }
    newUser.showAllFolder();
    string __folderName;
    fflush(stdin);
    cout << "Chon thu muc: ";
    getline(cin, __folderName);
    int idx = newUser.findFolder(__folderName);
    if (idx == -1)
    {
        cout << "Khong tim thay folder!" << endl;
        return;
    }
    if (newUser[idx].isEmpty())
    {
        cout << "Thu muc rong!" << endl;
        return;
    }
    newUser[idx].showAllDocument();
}

void addFolderToUser()
{
    string __tempFolderName;
    fflush(stdin);

    do
    {
        cout << "Nhap ten thu muc moi (Luu y: Khong duoc trung ten voi thu muc truoc do): ";
        getline(cin, __tempFolderName);
    } while (newUser.findFolder(__tempFolderName) != -1);

    Folder __tempFolder(__tempFolderName);
    newUser.addFolder(__tempFolder);
}

void deleteFolderFromUser()
{
    if (newUser.isEmpty())
    {
        cout << "Chua tao thu muc nao trong thu muc cua nguoi dung." << endl;
        return;
    }
    newUser.showAllFolder();
    string __tempFolderName;
    fflush(stdin);
    cout << "Chon thu muc muon xoa: ";
    getline(cin, __tempFolderName);
    newUser.deleteFolder(__tempFolderName);
}

void returnMenu()
{
    fflush(stdin);
    cout << "An nut bat ky de tro ve man hinh chinh" << endl;
    getchar();
    system("cls");
    main();
}
