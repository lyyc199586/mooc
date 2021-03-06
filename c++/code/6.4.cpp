// 6.4.cpp : 排序函数重载
//

#include <iostream>

using namespace std;

void sort(int &x, int &y);
void sort(int &x, int &y, int &z);
void sort(int &x, int &y, int &z, int &m);
void sort(int a[], int m);
void print(int a[], int m);

int main()
{
	int a, b, c, d;
	int data[100];
	int k, n, i;// k：type, n: counts
	cin >> k;
	switch (k) {
	case 1:
		cin >> a >> b;
		sort(a, b);
		cout << a << " " << b << endl; // a>b
		break;
	case 2:
		cin >> a >> b >> c;
		sort(a, b, c);
		cout << a << " " << b << " " << c << endl; // a>b>c
		break;
	case 3:
		cin >> a >> b >> c >> d;
		sort(a, b, c, d);
		cout << a << " " << b << " " << c << " " << d << endl;
		break;
	case 4:
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> data[i];
		}
		sort(data, n);
		print(data, n);
		break;
	}
	return 0;
}

void sort(int &a, int &b)
{
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
}

void sort(int &a, int &b, int &c)
{
	sort(a, b);// a>b
	sort(a, c);// a>c
	sort(b, c);// b>c
}

void sort(int &a, int &b, int &c, int &d)
{
	sort(a, b, c); // a>b>c
	sort(a, d);// a>d
	sort(b, c, d);// b>c>d
}

void sort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n-1-i; j++)
			sort(a[j], a[j + 1]);
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		if (i == n-1) cout << a[i] << endl;
		else cout << a[i] << ' ';
	}
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
