/*����һ�������ع��캯���������ࣨ20�֣�
��Ŀ���ݣ�

����һ�������ع��캯����������Date�����ݳ�Ա���ꡢ�¡��գ���Ա����������һ���������Ĺ��캯��Date(int,int,int)��һ�����������Ĺ��캯��(��������Ϊ1900��1��1��)��һ��������-��-�ա���ʽ��ʾ���ڵĺ�����һ�������ݳ�Ա��ֵ�ĺ���void
init(int,int,int)��

�������ж���Ĳ���Ҫ��
1.
�ֱ�ʹ��������ͬ�����ع��캯������������������󣨱���Ϊd1,d2��d2��ʼֵΪ2100-12-12����
2.
������-��-�ա���ʽ�ֱ���ʾ���������ֵ��
3. �������ݣ���init����Ϊd1��ֵ��
2��������-��-�ա���ʽ��ʾ����d1��ֵ����



�����ʽ:

��d1��ֵ������



�����ʽ��

d1��Ĭ��ֵ

d2�ĳ�ʼֵ

d1��ֵ���ֵ



����������

2011 4 29



���������

1900-1-1
2100-12-12
2011-4-29
*/

#include <iostream>

using namespace std;

class Date
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
