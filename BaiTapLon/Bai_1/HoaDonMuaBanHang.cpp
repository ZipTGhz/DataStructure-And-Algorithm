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
    HoaDonMuaBanHang(string maHoaDon = "Unknown", string maHang = "Unknown", bool loaiHoaDon = 0, long long soLuong = 0, string ngayMuaBan = "Unknown", long long giaMuaBan = 0)
    {
        this->maHoaDon = maHoaDon;
        this->maHang = maHang;
        this->loaiHoaDon = loaiHoaDon;
        this->ngayMuaBan = ngayMuaBan;
        this->giaMuaBan = giaMuaBan;
        this->soLuong = soLuong;
    }

    friend istream &operator>>(istream &cin, HoaDonMuaBanHang &_hoaDon)
    {
        fflush(stdin);
        cout << "Nhap ma hang: ";
        getline(cin, _hoaDon.maHang);
        cout << "Nhap loai hoa don(0 la Mua, 1 la Ban): ";
        cin >> _hoaDon.loaiHoaDon;
        cout << "Nhap so luong " << (_hoaDon.loaiHoaDon ? "ban" : "mua") << ": ";
        cin >> _hoaDon.soLuong;
        cout << "Nhap gia " << (_hoaDon.loaiHoaDon ? "ban" : "mua") << ": ";
        cin >> _hoaDon.giaMuaBan;
        return cin;
    }

    friend ostream &operator<<(ostream &cout, const HoaDonMuaBanHang &_hoaDon)
    {
        cout << _hoaDon.maHoaDon << " - " << _hoaDon.maHang << " - " << (_hoaDon.loaiHoaDon ? "Mua" : "Ban") << " - " << _hoaDon.soLuong << " - " << _hoaDon.ngayMuaBan << " - " << _hoaDon.giaMuaBan;
        return cout;
    }

    void setLoaiHoaDon(const bool &loaiHoaDon) { this->loaiHoaDon = loaiHoaDon; }
    void setSoLuong(const long long &soLuong) { this->soLuong = soLuong; }
    void setGiaMuaBan(const long long &giaMuaBan) { this->giaMuaBan = giaMuaBan; }
    void setMaHoaDon(const string &maHoaDon) { this->maHoaDon = maHoaDon; }
    void setMaHang(const string &maHang) { this->maHang = maHang; }
    void setNgayMuaBan(const string ngayMuaBan) { this->ngayMuaBan = ngayMuaBan; }

    const bool &getLoaiHoaDon() { return loaiHoaDon; }
    const bool &getLoaiHoaDon() const { return loaiHoaDon; }
    const long long &getSoLuong() { return soLuong; }
    const long long &getSoLuong() const { return soLuong; }
    const long long &getGiaMuaBan() { return giaMuaBan; }
    const long long &getGiaMuaBan() const { return giaMuaBan; }
    const string &getMaHoaDon() { return maHoaDon; }
    const string &getMaHoaDon() const { return maHoaDon; }
    const string &getMaHang() { return maHang; }
    const string &getMaHang() const { return maHang; }
    const string &getNgayMuaBan() { return ngayMuaBan; }
    const string &getNgayMuaBan() const { return ngayMuaBan; }
};
#endif
