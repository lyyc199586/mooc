/*设计一个多功能的MyTime类（20分）
题目内容：

设计一个多功能的MyTime类，设计多个重载的构造函数，可以设置时间，进行时间的加减运算，按各种可能的格式（24小时制、12小时制）输出时间。

注意：

（1）请考虑设置的时间的合理性（时0-23； 分0-59；秒0-59）。

（2）12小时制中，12:00:00前为AM， 12:00:00及以后为PM

（3）加减运算的加数、减数是一个时间的长度，单位为“时、分、秒”

（4）构造函数：没参数时，设置时间为0时 0分 0秒；有参数时，设置成给定的时、分、秒。

 在主函数中

（1）声明两个对象t1,t2，并通过构造函数初始化它们（t2初始化为为8：10：30）

（2）显示按12、14小时制显示t1、t2的时间。

（3）再设置t1的时间，数据由用户输入。

（4）再输入待加减的时间。

（5）t1加输入的时间，并按12小时和24小时制显示。

（6）t2减输入的时间，并按12小时和24小时制显示。



输入格式:

第一行为t1的时间，第二行为待加减的时间



输出格式：

显示按12、14小时制显示t1、t2的初始时间

t1加输入的待加减的时间按12小时和24小时制显示。

t2减输入的待加减的时间按12小时和24小时制显示



输入样例：

11 30 30

5 15 20



输出样例：

00:00:00 AM

00:00:00

08:10:30 AM

08:10:30

04:45:50 PM

16:45:50

02:55:10 AM

02:55:10
*/

#include <iostream>

using namespace std;

class MyTime
{
    int hour, minute, second;
public:
    MyTime()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    MyTime(int hour, int minute, int second)
    {
        this->hour = (hour>=0&&hour<=23)?hour:0;
        this->minute = (minute>=0&&minute<=59)?minute:0;
        this->second = (second>=0&&second<=59)?second:0;
    }
    void init(int hour, int minute, int second)
    {
        this->hour = (hour>=0&&hour<=23)?hour:0;
        this->minute = (minute>=0&&minute<=59)?minute:0;
        this->second = (second>=0&&second<=59)?second:0;
    }
    void print24()
    {
        if(hour>=10) cout<<hour;
        else cout<<"0"<<hour;
        cout<<":";
        if(minute>=10) cout<<minute;
        else cout<<"0"<<minute;
        cout<<":";
        if(second>=10) cout<<second;
        else cout<<"0"<<second;
        cout<<endl;
    }
    void print12()
    {
        if(hour>=12) cout<<"0"<<hour-12;
        else if(hour<10) cout<<"0"<<hour;
        else cout<<hour;
        cout<<":";
        if(minute>=10) cout<<minute;
        else cout<<"0"<<minute;
        cout<<":";
        if(second>=10) cout<<second;
        else cout<<"0"<<second;
        if(hour>12) cout<<" PM"<<endl;
        else cout<<" AM"<<endl;
    }
    void addtime(int ah, int am, int as)
    {

        second += as;
        if (second>59)
        {
            second -= 60;
            minute += 1;
        }
        minute += am;
        if (minute>59)
        {
            minute -= 60;
            hour += 1;
        }
        hour += ah;
        if (hour>24) hour -= 24;

    }
    void subtime(int sh, int sm, int ss)
    {
        second -= ss;
        if (second<0) {second += 60; minute -= 1;}
        minute -= sm;
        if (minute<0) {minute += 60; hour -= 1;}
        hour -= sh;
        if (hour<0) hour += 24;
    }
};

int main()
{
    int h1,m1,s1;
    int ah,am,as;
    cin>>h1>>m1>>s1;
    cin>>ah>>am>>as;
    MyTime t1;
    MyTime t2(8, 10, 30);
    t1.print12();
    t1.print24();
    t2.print12();
    t2.print24();
    t1.init(h1, m1, s1);
    t1.addtime(ah, am, as);
    t2.subtime(ah, am, as);
    t1.print12();
    t1.print24();
    t2.print12();
    t2.print24();
    return 0;
}

