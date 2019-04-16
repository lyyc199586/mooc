/*计算某个正整数平方根，并按要求输出（20分）
题目内容：

输入一个正整数。计算其平方根(用sqrt函数)，并将结果按取1~6位小数分六行显示出来。



输入格式:

输入一个正整数。



输出格式：


计算结果分6行显示，小数位数依次取1~6位。



输入样例：

2



输出样例：

1.4

1.41

1.414

1.4142

1.41421

1.414214
*/


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a;
    cin>>a;
    double r = sqrt(a);
    cout<<setiosflags(ios::fixed)<<setprecision(1)<<r<<endl;
    cout<<setprecision(2)<<r<<endl;
    cout<<setprecision(3)<<r<<endl;
    cout<<setprecision(4)<<r<<endl;
    cout<<setprecision(5)<<r<<endl;
    cout<<setprecision(6)<<r<<endl;
    return 0;
}
