#pragma once
#include <string>
#include "zVector.cpp"
#include "zPair.cpp"

using namespace std;

#ifndef __HoaDonMuaHang__cpp__
#define __HoaDonMuaHang__cpp__
class HoaDonMuaHang
{
private:
    int maHoaDon;
    zVector<zPair<int, int>> arr;
    int ngayMuaBan;
    int giaMuaBan;
    string loaiHoaDon;

public:
    HoaDonMuaHang(/* args */);
    ~HoaDonMuaHang();
};
#endif
