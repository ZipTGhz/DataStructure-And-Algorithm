#include <iostream>
#include <fstream>

#include "DanhMucMatHang.cpp"
#include "HoaDonMuaBanHang.cpp"

#define endl "\n"
#define HD_BAN true
#define HD_MUA false
using namespace std;

#ifndef MainApp__CPP
#define MainApp__CPP

class App
{
private:
    DanhMucMatHang danhSach;
    zVector<HoaDonMuaBanHang> HoaDon;
    string countHoaDon = "0000";

public:
    void mainMenu();
    void mode0();
    void mode1();
    void mode2();
    void mode3();
    void mode4();
    void mode5();
};

void App::mainMenu()
{
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
}

void App::mode0()
{
    cout << "Dang thoat chuong trinh..." << endl;
    exit(0);
}

void App::mode1()
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
        MatHang temp;
        string tempStr;
        getline(iFile, tempStr);
        if (tempStr == "END000")
            break;
        temp.setMaHang(tempStr);
        getline(iFile, tempStr), temp.setTenHang(tempStr);
        getline(iFile, tempStr), temp.setNhaSanXuat(tempStr);
        danhSach.addMat_Hang(temp);
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
        int pos = danhSach.findByMa_Hang(maHang);
        if (loaiHoaDon)
            danhSach[pos].setSoLuong(danhSach[pos].getSoLuong() - soLuong);
        else
            danhSach[pos].setSoLuong(danhSach[pos].getSoLuong() + soLuong);

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

void App::mode2()
{
    string nameFile;
    cout << "Nhap ten file muon xuat (VD: output.txt): ";
    cin >> nameFile;
    ofstream oFile(nameFile);
    export_DSMatHang_toFile(oFile, danhSach);

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

void App::mode3()
{
    system("cls");
    HoaDonMuaBanHang tempHoaDon;
    cin >> tempHoaDon;
    int pos = danhSach.findByMa_Hang(tempHoaDon.getMaHang());
    if (pos == -1)
    {
        if (tempHoaDon.getLoaiHoaDon() == HD_BAN)
        {
            cout << "Khong the ban mat hang khong ton tai!" << endl;
            return;
        }
        else
        {
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
            MatHang tempMatHang;
            tempMatHang.setMaHang(tempHoaDon.getMaHang());
            string tempStr;
            cout << "Nhap ten hang:";
            getline(cin, tempStr);
            tempMatHang.setTenHang(tempStr);
            cout << "Nhap ten nha san xuat: ";
            getline(cin, tempStr);
            tempMatHang.setNhaSanXuat(tempStr);
            danhSach.addMat_Hang(tempMatHang);
        }
    }
    pos = danhSach.findByMa_Hang(tempHoaDon.getMaHang());
    if (!tempHoaDon.getLoaiHoaDon())
        danhSach[pos].setSoLuong(danhSach[pos].getSoLuong() + tempHoaDon.getSoLuong());
    else if (danhSach[pos].getSoLuong() >= tempHoaDon.getSoLuong())
        danhSach[pos].setSoLuong(danhSach[pos].getSoLuong() - tempHoaDon.getSoLuong());
    else
    {
        cout << "Khong du so luong mat hang!" << endl;
        return;
    }
    tempHoaDon.setMaHoaDon(aGen.autoGenerate_MaHoaDon(countHoaDon));
    tempHoaDon.setNgayMuaBan(aGen.autoGenerateCurrentDay);
    HoaDon.push_back(tempHoaDon);
    cout << "Da luu thong tin hoa don vao co so du lieu!" << endl;
}

void App::mode4()
{
    system("cls");
    danhSach.displayAllMat_Hang();
}

void App::mode5()
{
    system("cls");
    danhSach.displayTonKho();
}
#endif