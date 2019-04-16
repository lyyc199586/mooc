/*设计并测试一个椭圆类（20分）
题目内容：

设计并测试一个名为Ellipse的椭圆类，其属性为圆心坐标及长半轴和短半轴的长度。设计一个构造函数（Ellipse(int,int,double,double)）对这些属性进行初始化，并通过成员函数计算出椭圆的面积（double
Area()）。

S（椭圆面积）=PI(圆周率)×a（长半轴）×b（短半轴）
其中PI取3.14

输入格式:

圆心坐标、长半轴和短半轴的长度



输出格式：

椭圆的面积

输入样例：

1 1 1 2

输出样例：

6.28
*/
#include <iostream>

using namespace std;

class Ellipse
{
    int x;
    int y;
    double major; // semi-major axis
    double minor; // semi-minor axis
public:
    Ellipse(int x, int y, double major, double minor)
    {
        this->x = x;
        this->y = y;
        this->major = major;
        this->minor = minor;
    }
    double Area()
    {return 3.14*major*minor;}
};

int main()
{
    int x,y;
    double a,b;
    cin>>x>>y>>a>>b;
    Ellipse e1(x, y, a, b);
    cout<<e1.Area()<<endl;
    return 0;
}
