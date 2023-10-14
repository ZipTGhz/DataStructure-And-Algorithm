#include <iostream>

using namespace std;

#ifndef __HoaDonMuaBanHang__cpp__
#define __HoaDonMuaBanHang__cpp__
class HoaDonMuaBanHang
{
private:
    bool loaiHoaDon; // 0 la Mua, 1 la Ban
    long long soLuong;
    long long giaMuaBan;
    string maHoaDon;
    string maHang;
    string ngayMuaBan;

public:
    HoaDonMuaBanHang(string maHoaDon = "Unkown", string maHang = "Unkown", bool loaiHoaDon = 0, long long soLuong = 0, string ngayMuaBan = "Unkown", long long giaMuaBan = 0)
    {
        this->maHoaDon = maHoaDon;
        this->maHang = maHang;
        this->loaiHoaDon = loaiHoaDon;
        this->ngayMuaBan = ngayMuaBan;
        this->giaMuaBan = giaMuaBan;
        this->soLuong = soLuong;
    }

    friend ostream &operator<<(ostream &cout, const HoaDonMuaBanHang &_hoaDon)
    {
        cout << _hoaDon.maHoaDon << " - " << _hoaDon.maHang << " - " << (_hoaDon.loaiHoaDon ? "Mua" : "Ban") << " - " << _hoaDon.soLuong << " - " << _hoaDon.ngayMuaBan << " - " << _hoaDon.giaMuaBan;
        return cout;
    }

    bool getLoaiHoaDon() { return loaiHoaDon; }
    bool getLoaiHoaDon() const { return loaiHoaDon; }
    long long getSoLuong() { return soLuong; }
    long long getSoLuong() const { return soLuong; }
    long long getGiaMuaBan() { return giaMuaBan; }
    long long getGiaMuaBan() const { return giaMuaBan; }
    string getMaHoaDon() { return maHoaDon; }
    string getMaHoaDon() const { return maHoaDon; }
    string getMaHang() { return maHang; }
    string getMaHang() const { return maHang; }
    string getNgayMuaBan() { return ngayMuaBan; }
    string getNgayMuaBan() const { return ngayMuaBan; }
};
#endif
