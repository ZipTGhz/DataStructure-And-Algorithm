#pragma once
#include <string>

using namespace std;

#ifndef __DanhMucMatHang__cpp__
#define __DanhMucMatHang__cpp__
class DanhMucMatHang
{
private:
    string maHang;
    string name;
    string nhaSanXuat;

public:
    DanhMucMatHang(string maHang = "Unknown", string name = "Unknown", string nhaSanXuat = "Unknown")
    {
        this->maHang = maHang;
        this->name = name;
        this->nhaSanXuat = nhaSanXuat;
    }

    DanhMucMatHang(const DanhMucMatHang &_temp)
    {
        maHang = _temp.maHang;
        name = _temp.name;
        nhaSanXuat = _temp.nhaSanXuat;
    }

    void operator=(const DanhMucMatHang &_temp)
    {
        maHang = _temp.maHang;
        name = _temp.name;
        nhaSanXuat = _temp.nhaSanXuat;
    }

    string getMaHang() { return maHang; }
    string getMaHang() const { return maHang; }
    string getName() { return name; }
    string getName() const { return name; }
    string getNhaSanXuat() { return nhaSanXuat; }
    string getNhaSanXuat() const { return nhaSanXuat; }

    ~DanhMucMatHang();
};
#endif