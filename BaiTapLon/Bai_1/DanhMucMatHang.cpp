#include <iostream>

using namespace std;

#ifndef __DanhMucMatHang__cpp__
#define __DanhMucMatHang__cpp__
class DanhMucMatHang
{
private:
    long long soLuong = 0;
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

    friend ostream &operator<<(ostream &cout, const DanhMucMatHang &_matHang)
    {
        cout << _matHang.maHang << endl;
        cout << _matHang.tenHang << endl;
        cout << _matHang.soLuong << endl;
        cout << _matHang.nhaSanXuat << endl;
        return cout;
    }

    void setSoLuong(const long long &soLuong) { this->soLuong = soLuong; }
    void setMaHang(const string &maHang) { this->maHang = maHang; }
    void setTenHang(const string &tenHang) { this->tenHang = tenHang; }
    void setNhaSanXuat(const string &nhaSanXuat) { this->nhaSanXuat = nhaSanXuat; }

    const long long &getSoLuong() { return soLuong; }
    const long long &getSoLuong() const { return soLuong; }
    const string &getMaHang() { return maHang; }
    const string &getMaHang() const { return maHang; }
    const string &getTenHang() { return tenHang; }
    const string &getTenHang() const { return tenHang; }
    const string &getNhaSanXuat() { return nhaSanXuat; }
    const string &getNhaSanXuat() const { return nhaSanXuat; }
};
#endif