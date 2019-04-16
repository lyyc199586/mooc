/*
读文件中的数字，算平均值（20分）
题目内容：

输入n个数字（实数），将他们写入文件out1.txt，数字之间用空格分开。然后再次打开该文件，读出全部数字，计算他们平均值并输出在屏幕上。



输入格式:

第一行输入数字个数n，以后的n行每行输入一个实数。



输出格式：

输出n个数平均值。格式：Avg=平均值



输入样例：

5

1.0

2.0

3.0

4.0

5.0



输出样例：

Avg=3
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int len;
    float avg=0, sum=0;
    cin>>len;
    float *p = new float[len];
    for(int i=0; i<len; i++){cin>>p[i]; sum += *(p+i);}
    avg = sum/len;
    ofstream out("out1.txt");
    if(!out) {cout<<"fail to open out1.txt"<<endl;}
    // for(int i=0; i<len; i++){
    //     out<<*(p+i)<<" ";
    // }
    out.close();
    cout<<"Avg="<<avg<<endl;
    delete[] p;
    system("pause");
    return 0;
}