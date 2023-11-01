#include "App.cpp"

void (*mode[])() = {&mode0, &mode1, &mode2, &mode3, &mode4, &mode5};

void chooseMode();
void returnMenu();

main()
{
    system("cls");
    mainMenu();
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
    (*mode[n])();
    returnMenu();
}

void returnMenu()
{
    cout << "Nhan phim bat ky de tro ve man hinh chinh..." << endl;
    fflush(stdin);
    if (getchar())
        main();
}