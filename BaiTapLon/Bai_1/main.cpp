#include <iostream>
#include <fstream>
#include <unistd.h>

// #include "zPair.cpp"
#include "zVector.cpp"
#include "DanhMucMatHang.cpp"
#include "HoaDonMuaBanHang.cpp"

#define endl "\n"

using namespace std;

zVector<DanhMucMatHang> MatHang;
zVector<HoaDonMuaBanHang> HoaDon;

string autoTab(int _tabTimes, const int &_strLen, const string &extraString = "")
{
    string _tab;
    _tabTimes -= _strLen / 8;
    while (_tabTimes-- > 0)
        _tab += "\t" + extraString;
    return _tab;
}

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
        exit(0);
    }
    cout << "Dang doc thong tin trong file..." << endl;
    while (true)
    {
        string maHoaDon, tenHang, nhaSanXuat;
        getline(iFile, maHoaDon);
        if (maHoaDon == "MS999")
            break;
        getline(iFile, tenHang);
        getline(iFile, nhaSanXuat);
        DanhMucMatHang temp(maHoaDon, tenHang, nhaSanXuat);
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
    // for (const auto &x : MatHang)
    //     cout << x << endl;
    // cout << endl
    //      << endl;
    // for (const auto &x : HoaDon)
    //     cout << x << endl;
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
    cout << "Dang trong qua trinh phat trien! Vui long quay tro lai o nhung phien ban sau..." << endl;
}
void mode4()
{
    cout << "Toan bo danh cac mat hang:" << endl;
    cout << "*****Ma_Hang********************Ten_Mat_Hang********************Nha_San_Xuat*****" << endl;
    // cout << "************Ten_Mat_Hang****************************Ton_Kho******" << endl;
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
    cout << "************Ten_Mat_Hang****************************Ton_Kho******" << endl;
    for (const DanhMucMatHang &x : MatHang)
    {
        if (x.getSoLuong() > 0)
        {
            cout << "* " << autoTab(8, 2) << "*" << endl;
            cout << "* " << x.getTenHang() << autoTab(7, x.getTenHang().length() + 2, "_") << x.getSoLuong() << "\t*" << endl;
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
        mode3();
    else if (n == 4)
        mode4();
    else if (n == 5)
        mode5();
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
