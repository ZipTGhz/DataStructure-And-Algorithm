#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>

#include "zVector.cpp"
#include "DanhMucMatHang.cpp"
#include "HoaDonMuaBanHang.cpp"

#define endl "\n"

using namespace std;

zVector<DanhMucMatHang> MatHang;
zVector<HoaDonMuaBanHang> HoaDon;

string autoTab(int _tabTimes, const int &_strLen)
{
    string _tab;
    _tabTimes -= _strLen / 8;
    while (_tabTimes-- > 0)
        _tab += "\t";
    return _tab;
}

string autoTab(int _tabTimes, const int &_strLen, const char &extraChar)
{
    string _tab, temp = "\t";
    temp.push_back(extraChar);
    _tabTimes -= _strLen / 8;
    while (_tabTimes-- > 0)
        _tab += temp;
    return _tab;
}

string currentDay = []
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return (to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year));
}();

void chooseMode();
void mode1()
{
    string nameFile;
    fflush(stdin);
    cout << "Nhap ten file muon doc (VD: input.txt): ";
    getline(cin, nameFile);
    ifstream iFile(nameFile);
    if (!iFile.is_open())
    {
        cout << "Loi doc file!" << endl;
        exit(-1);
    }
    cout << "Dang doc thong tin trong file..." << endl;
    while (true)
    {
        DanhMucMatHang temp;
        string tempStr;
        getline(iFile, tempStr);
        if (tempStr == "MS999")
            break;
        temp.setMaHang(tempStr);
        getline(iFile, tempStr), temp.setTenHang(tempStr);
        getline(iFile, tempStr), temp.setNhaSanXuat(tempStr);
        MatHang.push_back(temp);
    }
    while (!iFile.eof())
    {

        string maHoaDon, maHang, ngayMuaBan;
        bool loaiHoaDon;
        long long soLuong, giaMuaBan;
        getline(iFile, maHoaDon);
        if (maHoaDon == "")
            break;
        getline(iFile, maHang);
        iFile >> loaiHoaDon >> soLuong;
        iFile.ignore();
        getline(iFile, ngayMuaBan);
        iFile >> giaMuaBan;
        iFile.ignore();
        HoaDonMuaBanHang temp(maHoaDon, maHang, loaiHoaDon, soLuong, ngayMuaBan, giaMuaBan);
        for (int i = 0; i < MatHang.size(); i++)
        {
            if (MatHang[i].getMaHang() == maHang)
            {
                if (loaiHoaDon)
                    MatHang[i].setSoLuong(MatHang[i].getSoLuong() - soLuong);
                else
                    MatHang[i].setSoLuong(MatHang[i].getSoLuong() + soLuong);
            }
        }
        HoaDon.push_back(temp);
    }
    cout << "Nhap du lieu hoan tat!" << endl;
    iFile.close();
}
void mode2()
{
    string nameFile;
    cout << "Nhap ten file muon xuat (VD: output.txt): ";
    cin >> nameFile;
    ofstream oFile(nameFile);
    for (const DanhMucMatHang &x : MatHang)
    {
        oFile << x.getMaHang() << endl;
        oFile << x.getTenHang() << endl;
        oFile << x.getNhaSanXuat() << endl;
    }
    oFile << "MS999\n";

    for (const HoaDonMuaBanHang &x : HoaDon)
    {
        oFile << x.getMaHoaDon() << endl;
        oFile << x.getMaHang() << endl;
        oFile << x.getLoaiHoaDon() << endl;
        oFile << x.getSoLuong() << endl;
        oFile << x.getNgayMuaBan() << endl;
        oFile << x.getGiaMuaBan() << endl;
    }

    cout << "Da ghi thong tin qua ly ra file " << nameFile << endl;
    oFile.close();
}
void mode3()
{
    HoaDonMuaBanHang tempHoaDon;
    cin >> tempHoaDon;
    tempHoaDon.setNgayMuaBan(currentDay);
    int pos = -1;
    for (int i = 0; i < MatHang.size(); i++)
    {
        if (MatHang[i].getMaHang() == tempHoaDon.getMaHang())
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "Khong tim thay mat hang nao trong co so du lieu!" << endl;
        cout << "Ban co muon nhap san pham nay vao khong?" << endl;
        cout << "0 - KHONG\t1 - CO" << endl;
        cout << "Nhap lua chon cua ban: ";
        bool yourChoice;
        cin >> yourChoice;
        if (!yourChoice)
        {
            cout << "Ban da chon khong!" << endl;
            return;
        }
        fflush(stdin);
        DanhMucMatHang tempMatHang;
        tempMatHang.setMaHang(tempHoaDon.getMaHang());
        string tempStr;
        cout << "Nhap ten hang:";
        getline(cin, tempStr);
        tempMatHang.setTenHang(tempStr);
        cout << "Nhap ten nha san xuat: ";
        getline(cin, tempStr);
        tempMatHang.setNhaSanXuat(tempStr);
        MatHang.push_back(tempMatHang);
    }
    for (int i = 0; i < MatHang.size(); i++)
    {
        if (MatHang[i].getMaHang() == tempHoaDon.getMaHang())
        {
            if (!tempHoaDon.getLoaiHoaDon())
                MatHang[i].setSoLuong(MatHang[i].getSoLuong() + tempHoaDon.getSoLuong());
            else if (MatHang[i].getSoLuong() > tempHoaDon.getSoLuong())
                MatHang[i].setSoLuong(MatHang[i].getSoLuong() - tempHoaDon.getSoLuong());
            else
            {
                cout << "Khong du so luong mat hang!";
                return;
            }
        }
    }
    HoaDon.push_back(tempHoaDon);
    cout << "Da luu thong tin hoa don vao co so du lieu!" << endl;
}
void mode4()
{
    cout << "Toan bo danh cac mat hang:" << endl;
    cout << "*****Ma_Hang********************Ten_Mat_Hang********************Nha_San_Xuat*****" << endl;
    for (const DanhMucMatHang &x : MatHang)
    {
        if (x.getSoLuong() > 0)
        {
            cout << "* " << autoTab(10, 2) << "*" << endl;
            cout << "*    " << x.getMaHang() << autoTab(2, 10);
            cout << x.getTenHang() << autoTab(9, x.getTenHang().length() + 21);
            cout << x.getNhaSanXuat() << autoTab(10, x.getNhaSanXuat().length() + 64) << "*" << endl;
        }
    }
    cout << "* " << autoTab(10, 2) << "*" << endl;
    cout << "*********************************************************************************" << endl;
}
void mode5()
{
    int count = 0;
    for (const DanhMucMatHang &x : MatHang)
        if (x.getSoLuong() > 0)
            count++;
    cout << "Co " << count << " mat hang dang ton kho!" << endl;
    cout << "************Ten_Mat_Hang*******************************Ton_Kho***" << endl;
    for (const DanhMucMatHang &x : MatHang)
    {
        if (x.getSoLuong() > 0)
        {
            cout << "* " << autoTab(8, 2) << "*" << endl;
            cout << "* " << x.getTenHang() << autoTab(7, x.getTenHang().length() + 2, '_') << x.getSoLuong() << "\t*" << endl;
        }
    }
    cout << "* " << autoTab(8, 2) << "*" << endl;
    cout << "*****************************************************************" << endl;
}

void returnMenu();

main()
{
    system("cls");
    cout << "*************PHAN MEM QUAN LY CUA HANG*************" << endl;
    cout << "*                                                 *" << endl;
    cout << "*    1. Doc danh sach thong tin quan ly cua hang  *" << endl;
    cout << "*                                                 *" << endl;
    cout << "*    2. Ghi thong tin quan ly cua hang ra file    *" << endl;
    cout << "*                                                 *" << endl;
    cout << "*    3. Nhap/xuat cac mat hang                    *" << endl;
    cout << "*                                                 *" << endl;
    cout << "*    4. Hien toan bo danh sach cac mat hang       *" << endl;
    cout << "*                                                 *" << endl;
    cout << "*    5. Thong ke so luong mat hang ton kho        *" << endl;
    cout << "*                                                 *" << endl;
    cout << "*    0. Thoat chuong trinh                        *" << endl;
    cout << "*                                                 *" << endl;
    cout << "***************************************************" << endl;
    chooseMode();

    return 0;
}

void chooseMode()
{
    int n;
    cout << "Nhap lua chon cua ban: ";
    cin >> n;

    if (n == 1)
        mode1();
    else if (n == 2)
        mode2();
    else if (n == 3)
    {
        system("cls");
        mode3();
    }
    else if (n == 4)
    {
        system("cls");
        mode4();
    }
    else if (n == 5)
    {
        system("cls");
        mode5();
    }
    else if (n == 0)
    {
        cout << "Dang thoat chuong trinh..." << endl;
        usleep(500000);
        exit(0);
    }
    else
    {
        cout << "Khong tim thay lua chon duoc yeu cau!" << endl;
    }
    returnMenu();
}

// void mode2() {}
// void mode3() {}
// void mode4() {}
// void mode5() {}

void returnMenu()
{
    cout << "Nhan phim bat ky de tro ve man hinh chinh..." << endl;
    fflush(stdin);
    if (getchar())
    {
        main();
    }
}
