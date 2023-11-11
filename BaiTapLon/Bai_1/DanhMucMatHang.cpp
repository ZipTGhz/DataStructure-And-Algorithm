#include "MatHang.cpp"
#include "zVector.cpp"
#include "autoGen.cpp"
#include <fstream>

using namespace std;

#ifndef DanhMucMatHang__cpp
#define DanhMucMatHang__cpp

autoGen aGen;

class DanhMucMatHang
{
private:
    zVector<MatHang> danhSachMatHang;

public:
    void addMat_Hang(const string &, const string &, const string &);
    void addMat_Hang(const MatHang &);
    void displayAllMat_Hang() const;
    void displayTonKho() const;
    int findByMa_Hang(const string &) const;
    MatHang &operator[](size_t index) { return danhSachMatHang[index]; }
    const MatHang &operator[](size_t index) const { return danhSachMatHang[index]; }
    friend void export_DSMatHang_toFile(ofstream &, const DanhMucMatHang &);
};

void DanhMucMatHang::addMat_Hang(const string &maHang, const string &tenHang, const string &nhaSanXuat)
{
    MatHang matHang = {maHang, tenHang, nhaSanXuat};
    danhSachMatHang.push_back(matHang);
}
void DanhMucMatHang::addMat_Hang(const MatHang &matHang) { danhSachMatHang.push_back(matHang); }

void DanhMucMatHang::displayAllMat_Hang() const
{
    cout << "Toan bo danh cac mat hang:" << endl;
    cout << "*****Ma_Hang********************Ten_Mat_Hang********************Nha_San_Xuat*****" << endl;
    for (const MatHang &x : danhSachMatHang)
    {
        cout << "* " << aGen.autoTab(10, 2) << "*" << endl;
        cout << "*    " << x.getMaHang() << aGen.autoTab(2, 10);
        cout << x.getTenHang() << aGen.autoTab(8, x.getTenHang().length() + 16);
        cout << x.getNhaSanXuat() << aGen.autoTab(10, x.getNhaSanXuat().length() + 64) << "*" << endl;
    }
    cout << "* " << aGen.autoTab(10, 2) << "*" << endl;
    cout << "*********************************************************************************" << endl;
}
void DanhMucMatHang::displayTonKho() const
{
    int count = 0;
    cout << "************Ten_Mat_Hang*******************************Ton_Kho***" << endl;
    for (const MatHang &x : danhSachMatHang)
    {
        if (x.getSoLuong() > 0)
        {
            ++count;
            cout << "* " << aGen.autoTab(8, 2) << "*" << endl;
            cout << "* " << x.getTenHang() << aGen.autoTab(7, x.getTenHang().length() + 2, '_') << x.getSoLuong() << "\t*" << endl;
        }
    }
    cout << "* " << aGen.autoTab(8, 2) << "*" << endl;
    cout << "*****************************************************************" << endl;
    cout << "Co " << count << " mat hang dang ton kho!" << endl;
}

int DanhMucMatHang::findByMa_Hang(const string &maHang) const
{
    for (int i = 0; i < danhSachMatHang.size(); i++)
    {
        if (danhSachMatHang[i].getMaHang() == maHang)
            return i;
    }
    return -1;
}

void export_DSMatHang_toFile(ofstream &oFile, const DanhMucMatHang &danhSach)
{
    for (const MatHang &x : danhSach.danhSachMatHang)
    {
        oFile << x.getMaHang() << endl;
        oFile << x.getTenHang() << endl;
        oFile << x.getNhaSanXuat() << endl;
    }
    oFile << "END000\n";
}

#endif