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

