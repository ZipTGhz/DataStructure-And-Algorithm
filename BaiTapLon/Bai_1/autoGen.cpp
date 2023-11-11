#include <string>
#include <ctime>

using namespace std;

#ifndef autoGen_cpp
#define autoGen_cpp
class autoGen
{
private:
    time_t now = time(0);
    tm *ltm = localtime(&now);

public:
    autoGen() {}

    string autoGenerateCurrentDay = (to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year));
    string generateMaHoaDon = ("HD" + to_string(1900 + ltm->tm_year) + to_string(1 + ltm->tm_mon) + to_string(ltm->tm_mday));

    string autoTab(int _tabTimes, const int &_strLen)
    {
        string _tab;
        _tabTimes -= _strLen / 8;
        while (_tabTimes-- > 0)
            _tab += "\t";
        return _tab;
    }
    string autoTab(int _tabTimes, const int &_strLen, const char &extraChar)
    {
        string _tab, temp = "\t";
        temp.push_back(extraChar);
        _tabTimes -= _strLen / 8;
        while (_tabTimes-- > 0)
            _tab += temp;
        return _tab;
    }

    string __plusOne(string countHoaDon)
    {
        for (auto it = countHoaDon.rbegin(); it != countHoaDon.rend(); it++)
        {
            if (*it != '9')
            {
                (*it)++;
                break;
            }
            *it = '0';
        }
        return countHoaDon;
    }

    string autoGenerate_MaHoaDon(string &countHoaDon)
    {
        countHoaDon = __plusOne(countHoaDon);
        return generateMaHoaDon + countHoaDon;
    }
};
#endif