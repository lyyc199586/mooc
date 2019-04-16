#include <iostream>

using namespace std;

class Date()
{
    int year, month, day;
public:
    Date(int, int, int);
    Date():year(1900), month(1), day(1) {}
    void show();
    void init(int, int, int);
};

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::init(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

void Date::show()
{
    cout<<year<<"-"<<month<<"-"<<day<<endl;
}

int main()
{
    Date d1;
    Date d2(2100,12,12);
    int yy, mm, dd;
    cin>>yy>>mm>>dd;
    d1.show();
    d2.show();
    d1.init(yy, mm, dd);
    d1.show();
    return 0;
}




