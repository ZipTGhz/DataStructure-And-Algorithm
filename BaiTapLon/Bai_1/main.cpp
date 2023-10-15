#include <iostream>
#include <fstream>
#include <unistd.h>

#include "zVector.cpp"
#include "autoGen.cpp"
#include "DanhMucMatHang.cpp"
#include "HoaDonMuaBanHang.cpp"

#define endl "\n"

using namespace std;

zVector<DanhMucMatHang> MatHang;
zVector<HoaDonMuaBanHang> HoaDon;

string countHoaDon = "0000";
autoGen aGen;

void chooseMode();
void mode0();
void mode1();
void mode2();
void mode3();
void mode4();
void mode5();

void (*mode[])() = {&mode0, &mode1, &mode2, &mode3, &mode4, &mode5};

int findByMaHang(const string &);
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
    do
    {
        cout << "Nhap lua chon cua ban: ";
        cin >> n;
    } while (n < 0 || n > 5);
    (*mode[n])();
    returnMenu();
}

void mode0()
{
    cout << "Dang thoat chuong trinh..." << endl;
    usleep(300000);
    exit(0);
}

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
        int pos = findByMaHang(maHang);
        if (loaiHoaDon)
            MatHang[pos].setSoLuong(MatHang[pos].getSoLuong() - soLuong);
        else
            MatHang[pos].setSoLuong(MatHang[pos].getSoLuong() + soLuong);

        HoaDon.push_back(temp);
    }
    for (auto it = HoaDon.rbegin(); it != HoaDon.rend(); it++)
    {
        if ((*it).getMaHoaDon().find(aGen.generateMaHoaDon) == string::npos)
            break;
        countHoaDon = aGen.__plusOne(countHoaDon);
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
    system("cls");
    HoaDonMuaBanHang tempHoaDon;
    cin >> tempHoaDon;
    int pos = findByMaHang(tempHoaDon.getMaHang());
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
    pos = findByMaHang(tempHoaDon.getMaHang());
    if (!tempHoaDon.getLoaiHoaDon())
        MatHang[pos].setSoLuong(MatHang[pos].getSoLuong() + tempHoaDon.getSoLuong());
    else if (MatHang[pos].getSoLuong() >= tempHoaDon.getSoLuong())
        MatHang[pos].setSoLuong(MatHang[pos].getSoLuong() - tempHoaDon.getSoLuong());
    else
    {
        cout << "Khong du so luong mat hang!";
        return;
    }
    tempHoaDon.setMaHoaDon(aGen.autoGenerate_MaHoaDon(countHoaDon));
    tempHoaDon.setNgayMuaBan(aGen.autoGenerateCurrentDay);
    HoaDon.push_back(tempHoaDon);
    cout << "Da luu thong tin hoa don vao co so du lieu!" << endl;
}

void mode4()
{
    system("cls");
    cout << "Toan bo danh cac mat hang:" << endl;
    cout << "*****Ma_Hang********************Ten_Mat_Hang********************Nha_San_Xuat*****" << endl;
    for (const DanhMucMatHang &x : MatHang)
    {
        cout << "* " << aGen.autoTab(10, 2) << "*" << endl;
        cout << "*    " << x.getMaHang() << aGen.autoTab(2, 10);
        cout << x.getTenHang() << aGen.autoTab(8, x.getTenHang().length() + 16);
        cout << x.getNhaSanXuat() << aGen.autoTab(10, x.getNhaSanXuat().length() + 64) << "*" << endl;
    }
    cout << "* " << aGen.autoTab(10, 2) << "*" << endl;
    cout << "*********************************************************************************" << endl;
}

void mode5()
{
    system("cls");
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
            cout << "* " << aGen.autoTab(8, 2) << "*" << endl;
            cout << "* " << x.getTenHang() << aGen.autoTab(7, x.getTenHang().length() + 2, '_') << x.getSoLuong() << "\t*" << endl;
        }
    }
    cout << "* " << aGen.autoTab(8, 2) << "*" << endl;
    cout << "*****************************************************************" << endl;
}

// Return position if maHang is found or -1 otherwise.
int findByMaHang(const string &_maHang)
{
    for (int i = 0; i < MatHang.size(); i++)
    {
        if (MatHang[i].getMaHang() == _maHang)
            return i;
    }
    return -1;
}

void returnMenu()
{
    cout << "Nhan phim bat ky de tro ve man hinh chinh..." << endl;
    fflush(stdin);
    if (getchar())
        main();
}
