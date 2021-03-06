// 8.5.cpp : 矩阵对角线元素之和
//
//题目内容：
//
//编写函数，求n阶方阵的对角线元素之和。编写主程序，用户输入矩阵的阶数n，动态申请n*n的存储空间，再输入n行、n列的元素，调用函数求矩阵的对角元素之和，在主函数中输出这个和。设元素均为整数。n >= 1。
//
//函数格式：int   sumDiagonal(int *a, int n);
//
//输入格式:
//
//一个正整数n，表示矩阵的阶数。
//
//n行、n列的矩阵元素。数据间用空格隔开。
//
//输出格式：
//
//一个整数
//
//输入样例：
//
//3
//
//6 1 2
//
//1 13 6
//
//62 4 35
//
//输出样例：
//
//54

#include <iostream>

using namespace std;

int   sumDiagonal(int **a, int n) {
	int sum = 0, i;
	for (i = 0; i < n; i++) {
		sum += a[i][i];
	}
	return sum;
}

int main()
{
	int n, i, j;
	int **p;
	cin >> n;
	p = new int *[n];
	for (i = 0; i < n; i++) {
		p[i] = new int[n];
	}

	//input data
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> *(*(p + i) + j);
	
	cout << sumDiagonal(p, n);
	delete[]p;
	return 0;
}

