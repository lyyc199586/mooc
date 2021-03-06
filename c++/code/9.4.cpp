//设计MyTime类（20分）
//题目内容：
//
//设计一个MyTime类，成员函数SetTime()设置时间，print_12()以12（0 - 11）小时制显示时间（AM上午，PM下午），print_24()以24（0 - 23）小时制显示时间。
//
//输入格式 :
//
//所需设置时间的时、分、秒
//
//输出格式：
//
//按照12小时制和24小时制依次显示时间, 注意时间格式中的冒号是英文冒号, 时分秒都是两位，AM, PM前有一个空格，晚上12:00是00 : 00 : 00 AM，中午十二点是00 : 00 : 00 PM。
//
//输入样例：
//
//13 23 34
//
//输出样例：
//
//01:23 : 34 PM
//
//13 : 23 : 34

#include <iostream>

using namespace std;

class MyTime {
	int hour, min, sec;
public:
	void SetTime(int,int,int);
	void print_12();
	void print_24();
};

void MyTime::SetTime(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}

void MyTime::print_12()
{
	if (hour < 13)cout << hour << ':' << min << ':' << sec << ' ' << "AM" << endl;
	else cout<< hour - 12 << ':' << min << ':' << sec << ' ' << "PM" << endl;
}

void MyTime::print_24()
{
	cout << hour << ':' << min << ':' << sec << endl;
}

int main()
{
	int _hour, _min, _sec;
	MyTime time1;
	cin >> _hour >> _min >> _sec;
	time1.SetTime(_hour, _min, _sec);
	time1.print_12();
	time1.print_24();
	system("pause");
	return 0;
}

//本段只满足了用例1 :)