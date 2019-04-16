/*纯虚函数与基类指针数组的应用（20分）
题目内容：

定义抽象基类Shape,
其中纯虚函数printName（）输出几何图形的名称和相应的成员数据、
纯虚函数printArea（）计算几何图形的面积。并由Shape类派生出5个派生类：
Circle（圆形），数据成员为半径、Square(正方形) ，数据成员为边长、
Rectangle(长方形) ，数据成员为长和宽、Trapezoid(梯形) ，
数据成员为上底、下底和高、Triangle(三角形) ，数据成员为底和高。
测试过程，定义一个指向基类的指针数组，
使其每个元素指向一个动态产生的派生类对象，
分别调用相应的成员函数显示各个几何图形的属性及面积，
最终输出总面积值。



输入格式:

依次输入圆半径、正方形边长、
长方形长宽、梯形上底下底和高、
三角形底边和高，均为实数。



输出格式：

请参考输出样例，
建议直接复制样例中的部分文字粘贴进自己的代码。
圆周率取 3.14159

注意输出中的标点符号、空格。

输入样例：

10
5
2 4
1 2 3
4 3



输出样例：

圆:半径=10,面积:314.159
正方形:边长=5,面积:25
长方形:长=2,宽=4,面积:8
梯形:上底=1,下底=2,高=3,面积:4.5
三角形:底边=4,高=3,面积:6
总面积:357.659
*/

#include<iostream>
#include <cstdlib>

# define PI 3.14159
using namespace std;

class Shape
{
private:
public:
	virtual void printName() = 0;
	virtual double printArea() = 0;
	Shape()
	{}
	~Shape()
	{}
};
class Circle:public Shape
{
private:
	double radius;
public:
	Circle(double radius)
	{
		this->radius = radius;
	}
	virtual void printName()
	{
		cout << "圆:半径=" << radius << ",";
	}
	virtual double printArea()
	{
		double area;
		area = radius*radius*PI;
		cout << "面积:" << area<<endl;
		return area;
	}
	~Circle()
	{
	}
};
class Rectangle :public Shape
{
private:
	double width;
	double height;
public:
	Rectangle(double width,double height)
	{
		this->width = width;
		this->height = height;
	}
	virtual void printName()
	{
		cout << "长方形:长=" << height << ",宽="<<width<<",";
	}
	virtual double printArea()
	{
		double area;
		area = width*height;
		cout << "面积:" << area << endl;
		return area;
	}
	~Rectangle()
	{
	}
};
class Square :public Shape
{
private:
	double side;
public:
	Square(double side)
	{
		this->side = side;
	}
	virtual void printName()
	{
		cout << "正方形:边长=" << side << ",";
	}
	virtual double printArea()
	{
		double area;
		area = side*side;
		cout << "面积:" << area << endl;
		return area;
	}
	~Square()
	{
	}
};
class Trapezoid :public Shape
{
private:
	double upside;
	double downside;
	double height;
public:
	Trapezoid(double upside,double downside,double height)
	{
		this->upside = upside;
		this->downside = downside;
		this->height = height;
	}
	virtual void printName()
	{
		cout << "梯形:上底=" << upside << ",下底="<<downside<<",高="<<height<<",";
	}
	virtual double printArea()
	{
		double area;
		area = (upside + downside) / 2 * height;
		cout << "面积:" << area << endl;
		return area;
	}
	~Trapezoid()
	{
	}
};
class Triangle :public Shape
{
private:
	double downside;
	double height;
public:
	Triangle(double downside, double height)
	{
		this->downside = downside;
		this->height = height;
	}
	virtual void printName()
	{
		cout << "三角形:底边=" << downside << ",高=" << height << ",";
	}
	virtual double printArea()
	{
		double area;
		area = downside / 2 * height;
		cout << "面积:" << area << endl;
		return area;
	}
	~Triangle()
	{
	}
};


int main()
{
	double sumArea = 0;
	double radius, side, heightRect, widthRect, upsideTra, downsideTra, heightTra, heightTri, downsideTri;
	cin >> radius >> side >> heightRect >> widthRect >> upsideTra >> downsideTra >> heightTra >> downsideTri >> heightTri;
	Shape *all[5];
	all[0] = new Circle(radius);
	all[1] = new Square(side);
	all[2] = new Rectangle(widthRect, heightRect);
	all[3] = new Trapezoid(upsideTra, downsideTra, heightTra);
	all[4] = new Triangle(downsideTri, heightTri);
	for (int i = 0; i < 5; i++)
	{
		all[i]->printName();
		sumArea = sumArea + all[i]->printArea();
	}
	cout << "总面积:" << sumArea << endl;
	system("pause");
	return 0;
}
