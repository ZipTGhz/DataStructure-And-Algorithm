#include <iostream>

using namespace std;

#ifndef __DanhMucMatHang__cpp__
#define __DanhMucMatHang__cpp__
class DanhMucMatHang
{
private:
    int soLuong = 0;
    string maHang;
    string tenHang;
    string nhaSanXuat;

public:
    DanhMucMatHang(string maHang = "Unknown", string tenHang = "Unknown", string nhaSanXuat = "Unknown")
    {
        this->maHang = maHang;
        this->tenHang = tenHang;
        this->nhaSanXuat = nhaSanXuat;
    }

    DanhMucMatHang(const DanhMucMatHang &_temp)
    {
        maHang = _temp.maHang;
        tenHang = _temp.tenHang;
        nhaSanXuat = _temp.nhaSanXuat;
    }

    void operator=(const DanhMucMatHang &_temp)
    {
        maHang = _temp.maHang;
        tenHang = _temp.tenHang;
        nhaSanXuat = _temp.nhaSanXuat;
    }

    friend ostream &operator<<(ostream &cout, const DanhMucMatHang &_matHang)
    {
        cout << _matHang.maHang << endl;
        cout << _matHang.tenHang << endl;
        cout << _matHang.soLuong << endl;
        cout << _matHang.nhaSanXuat << endl;
        return cout;
    }

    void setSoLuong(const int &soLuong) { this->soLuong = soLuong; }

    int getSoLuong() { return soLuong; }
    int getSoLuong() const { return soLuong; }
    string getMaHang() { return maHang; }
    string getMaHang() const { return maHang; }
    string getTenHang() { return tenHang; }
    string getTenHang() const { return tenHang; }
    string getNhaSanXuat() { return nhaSanXuat; }
    string getNhaSanXuat() const { return nhaSanXuat; }
};
#endif