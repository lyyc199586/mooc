/*重载加法运算符的复数运算（20分）
题目内容：

定义一个复数类，并重载加法运算符（+）和赋值运算符（=）
以适用对复数运算的要求。



输入格式:

依次输入两个复数的实部和虚部



输出格式：

先按照要求格式输出两个复数，然后输出这两个复数的和



输入样例：

1 2
3 4


输出样例：

1+j2
3+j4
4+j6
*/


#include <iostream>

using namespace std;

class Complex{
    double Re;
    double Im;
public:
    Complex(double r = 0, double i = 0): Re(r), Im(i) {}
    double Real(){return Re;}
    double Imag(){return Im;}
    Complex operator+ (Complex&);
    Complex operator= (Complex);
    void Show(){cout<<Re<<"+j"<<Im<<endl;}
    ~Complex(){};
};

Complex Complex::operator+ (Complex &c){ //c or &c -> both ok
    Complex temp;
    temp.Re = Re + c.Re;
    temp.Im = Im + c.Im;
    return temp;
}

Complex Complex::operator= (Complex d){ // d or &d -> d ok, &d error
    this->Re = d.Re;
    this->Im = d.Im;
    return *this;
}
//不用指针无法进行赋值？

int main()
{
    double r1, r2;
    double i1, i2;
    cin>>r1>>i1;
    cin>>r2>>i2;
    Complex c1(r1, i1);
    Complex c2(r2, i2);
    Complex c3;
    c1.Show();
    c2.Show();
    c3 = c1 + c2;
    c3.Show();
    return 0;
}
