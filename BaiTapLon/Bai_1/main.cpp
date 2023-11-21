#include "App.cpp"

void (App::*mode[])() = {&App::mode0, &App::mode1, &App::mode2, &App::mode3, &App::mode4, &App::mode5};
App mainApp;

void chooseMode();
void returnMenu();

main()
{
    system("cls");
    mainApp.mainMenu();
    chooseMode();
    return 0;
}

void chooseMode()
{
    int n;
    do
    {
        cout << "Nhap lua chon cua ban: ";
        if (cin >> n)
            continue;
        cerr << "Loi chuong trinh! Ban da nhap dinh dang khong phai so!" << endl;
        exit(-1);
    } while (n < 0 || n > 5);
    (mainApp.*mode[n])();
    returnMenu();
}

void returnMenu()
{
    cout << "Nhan phim bat ky de tro ve man hinh chinh..." << endl;
    fflush(stdin);
    if (getchar())
        main();
}