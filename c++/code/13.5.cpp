/*
读文件中的字符并排序输出（20分）
题目内容：

输入n个字符写入文本文件A.txt，字符间用空格分开。在打开该文件，读取所有字符并排序后，按从小到大顺序写入B.txt（字符间用空格分开），同时将文件B的内容显示在屏幕上。



输入格式:

第一行输入数字个数n(100>n>=1)，第2行输入n个字符(以空格分开）。



输出格式：

按从小到大顺序输出n个字符(以空格分开）



输入样例：

5

Z  Y  X  A  C



输出样例：

A C X Y Z
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // initialization
    int len;
    char *p = new char[len];

    // cin>>data
    cin>>len;
    for(int i=0; i<len; i++){cin>>p[i];}

    // >>A
    /*
    ofstream f1("A.txt");
    for(int i=0; i<len; i++){
        f1<<p[i]<<" ";
        if(p[i]=='\0'){break;}
    }
    f1.close();

    // A>>
    ifstream f2("A.txt");
    for(int i=0; i<len; i++){f2>>p[i];}
    f2.close();
    */

    // 冒泡排序
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1-i; j++){
            if(p[j]>p[j+1]){
                int temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    /*
    // B<<
    ofstream f3("B.txt");
    for(int i=0; i<len; i++){
        f3<<p[i]<<" ";
        if(p[i]=='\0'){break;}
    }
    f3.close();
    */

    // cout<<
    for(int i=0; i<len; i++){
        if(i==0){cout<<p[i];}
        else{cout<<" "<<p[i];}
        if(p[i]=='\0'){break;}
    }
    delete[] p;

    //system("pause");
    return 0;
}