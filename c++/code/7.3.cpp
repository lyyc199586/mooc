// 7.3.cpp : 数组清零
//
//题目内容：
//
//编写一个函数，用于将一个int类型的数组清零（即将指定前n项元素全部置为0）数组以 - 1结尾，
//且 - 1不包括在此数组中。要求数组使用地址传递（传指针）。
//提示：本题只要在形参中使用整型指针，对应的实参是数组名（因为数组名是数组的首地址），函数
//中仍使用下标访问数组元素。
//
//例如 int a[100], *p = a;   //a是数组a的首地址。则p[i]相当于a[i]。
//
//输入格式 :
//第一行数是数组元素，第二行的数是需清零的元素个数n
//
//输出格式：
//清零后的数组元素, 注意最后一个元素后不要带空格。
//
//输入样例：
//
//503 87 512 61 908 170 897 275 653 426 154 509 612 677 765 703 - 1
//
//5
//
//输出样例：
//
//0 0 0 0 0 170 897 275 653 426 154 509 612 677 765 703

#include <iostream>

using namespace std;

void clear(int *p, int num) {
	for (int i = 0; i < num; i++)
		p[i] = 0;
}

int main()
{
	int a[100];
	int n;
	static int i;
	for (i = 0; i < 100; i++) {
		cin >> a[i];
		if (a[i] == -1) break;
	}
	cin >> n;
	clear(a, n);
	for (int j = 0; j < i; j++) {
		cout << a[j];
		if (j != i - 1) cout << " ";
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
