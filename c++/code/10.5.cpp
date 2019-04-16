/*���һ���๦�ܵ�MyTime�ࣨ20�֣�
��Ŀ���ݣ�

���һ���๦�ܵ�MyTime�࣬��ƶ�����صĹ��캯������������ʱ�䣬����ʱ��ļӼ����㣬�����ֿ��ܵĸ�ʽ��24Сʱ�ơ�12Сʱ�ƣ����ʱ�䡣

ע�⣺

��1���뿼�����õ�ʱ��ĺ����ԣ�ʱ0-23�� ��0-59����0-59����

��2��12Сʱ���У�12:00:00ǰΪAM�� 12:00:00���Ժ�ΪPM

��3���Ӽ�����ļ�����������һ��ʱ��ĳ��ȣ���λΪ��ʱ���֡��롱

��4�����캯����û����ʱ������ʱ��Ϊ0ʱ 0�� 0�룻�в���ʱ�����óɸ�����ʱ���֡��롣

 ����������

��1��������������t1,t2����ͨ�����캯����ʼ�����ǣ�t2��ʼ��ΪΪ8��10��30��

��2����ʾ��12��14Сʱ����ʾt1��t2��ʱ�䡣

��3��������t1��ʱ�䣬�������û����롣

��4����������Ӽ���ʱ�䡣

��5��t1�������ʱ�䣬����12Сʱ��24Сʱ����ʾ��

��6��t2�������ʱ�䣬����12Сʱ��24Сʱ����ʾ��



�����ʽ:

��һ��Ϊt1��ʱ�䣬�ڶ���Ϊ���Ӽ���ʱ��



�����ʽ��

��ʾ��12��14Сʱ����ʾt1��t2�ĳ�ʼʱ��

t1������Ĵ��Ӽ���ʱ�䰴12Сʱ��24Сʱ����ʾ��

t2������Ĵ��Ӽ���ʱ�䰴12Сʱ��24Сʱ����ʾ



����������

11 30 30

5 15 20



���������

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

