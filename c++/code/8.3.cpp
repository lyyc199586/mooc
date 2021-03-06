// 8.3.cpp : 遍历二维数组
//
//题目内容：
//
//用户首先输入两个整数m和n, 然后输入m*n个元素，建立一个m*n的二维数组。要求使用 行指针 来遍历这个二维数组，输出该数组中所有元素的和。
//
//输入格式 :
//
//首先输入两个整数m和n, 然后依次输入m*n个元素
//
//输出格式：
//
//二维数组中所有元素的和
//
//输入样例：
//
//2 3
//
//1 3 5
//
//2 4 6
//
//输出样例：
//
//21


//动态申请二维数组
#include <iostream>
using namespace std;
int main()
{
	int **a;  //指向指针的指针 
	int n, m;//n行 m列 
	int i, j, sum=0;
	cin >> n >> m; //输入行数和列数

	//申请空间
	a = new int *[n];  //n个 int 指针 数组
	for (i = 0; i < n; i++)    //n个大小为m的一维数组
	{
		a[i] = new int[m]; //1个大小为m的一维数组，a[i]是int指针
	}

	//输入数据
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			//cin>>a[i][j];//输入 
			cin >> *(*(a + i) + j);//同上a相当于行指针 

		}
	}

	//
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			//cout<<a[i][j]<<"\t";//输出 
			sum += *(*(a + i) + j);

		}
	}
	cout << sum;
	//释放申请的空间！！！
	for (i = 0; i < n; i++) //释放n个大小为m的一维数组
	{
		delete[]a[i];
	}
	delete[]a;//释放int指针数组
	return 0;
}

