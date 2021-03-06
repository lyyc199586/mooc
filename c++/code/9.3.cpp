//设计并测试Trapezium类（20分）
//题目内容：
//
//设计并测试一个名为Trapezium的梯形类，其属性为梯形的四个顶点的坐标。该梯形上边和下边均和x轴平行。
//根据类的封装性要求，在类的声明中用8个私有的整型变量表示4个点的坐标值，声明成员函数initial(int, int, int, int, int, int, int, int)初始化数据成员，
//函数GetPosition(int&, int&, int&, int&, int&, int&, int&, int&)读取坐标值，函数Area()计算面积。
//
//输入格式 :
//
//梯形四个顶点的坐标，
//
//输出格式：
//
//梯形的面积，依次为左上(x1, y1)、右上(x2, y2)、左下(x3, y3)和右下(x4, y4)角的顶点。
//
//输入样例：
//
//3 2 5 2 1 - 4 7 - 4
//
//输出样例：
//
//24

#include <iostream>

using namespace std;

class Trapezium
{
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;
public:
	void inital(int, int, int, int, int, int, int, int);
	void GetPosition(int&, int&, int&, int&, int&, int&, int&, int&);
	void Area();
};

void Trapezium::inital(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4)
{
	x1 = _x1;
	x2 = _x2;
	x3 = _x3;
	x4 = _x4;
	y1 = _y1;
	y2 = _y2;
	y3 = _y3;
	y4 = _y4;
}

void Trapezium::GetPosition(int &a, int &b, int &c, int &d, int &e, int &f, int &g, int &h)
{
	cout << a << " " << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << endl;
}

void Trapezium::Area()
{
	float s;
	s = (x2 - x1 + x4 - x3)*(y1 - y3) / 2.0;
	cout << s << endl;
}

int main()
{
	int _x1; int _y1; int _x2; int _y2; int _x3; int _y3; int _x4; int _y4;
	cin >> _x1 >> _y1 >> _x2 >> _y2 >> _x3 >> _y3 >> _x4 >> _y4;
	Trapezium t1;
	t1.inital(_x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4);
	t1.Area();
	system("pause");
	return 0;
}
