// 7.4.cpp : 使用函数指针切换加密方法
//题目内容：
//编写两个加密函数，第一个函数使用凯撒加密法，即将将原来的小写字母用字母表中其后面的第3个字母
//的大写形式来替换，大写字母按同样规则用小写字母替换，可将字母表看成是首末衔接的。
//例如"AMDxyzXYZ" 加密为 "dpgABCabc"。第二个函数使用单双号加密法，即将字符串"abcde", 
//根据单双号区分为两个字符串"ace"和"bd"，再连接在一起成为密文"acebd"。
//
//用户输入一个字符串作为明文，再输入数字1或2，输入1使用第一个函数加密并输出密文，
//输入2使用第二个函数加密并输出密文。要求使用函数指针来切换加密函数。
//
//提示：三个函数的原型可设为：
//
//void caesar(char s[]);
//
//void oddeven(char s[]);
//
//void cipher(void(*f)(char s[]), char s[]);//形参为指向函数的指针，对应实参可为相应格式的
//函数名。
//
//输入格式:
//
//一个字符串作为明文，再输入数字1或2，输入1使用第一个函数加密并输出密文，输入2使用第二个函数
//加密并输出密文。
//
//输出格式：
//
//加密后的密文
//
//输入样例：
//
//jacky
//
//2
//
//输出样例：
//
//jcyak

#include <iostream>
#include <string.h>

using namespace std;
static int length;

void caesar(char s[])
{
	for (int i = 0; i < length; i++)
	{
		if (s[i] <= 'Z' && s[i] >= 'A')
		{
			s[i] = (s[i] - 'A' + 3) % 26 + 'a';
		}
		else
		{
			s[i] = (s[i] - 'a' + 3) % 26 + 'A';
		}
	}
}

void oddeven(char s[])
{
	char s1[100], s2[100];
	int num_1 = 0, num_2 = 0;
	for (int i = 0; i < length; i++)
	{
		if (i % 2 == 0)
		{
			s1[num_1] = s[i];
			num_1++;
		}
		else
		{
			s2[num_2] = s[i];
			num_2++;
		}
	}


	for (int i = 0; i < num_1; i++)
	{
		s[i] = s1[i];
	}

	for (int i = 0; i < num_2; i++)
	{
		s[i + num_1] = s2[i];
	}
}
void cipher(void(*f)(char s[]), char s[])
{
	(*f)(s);
}

int main()
{
	void(*f)(char s[]);
	char s[100];
	int choice = 1;
	cin.getline(s, 100);
	cin >> choice;
	length = strlen(s);

	if (choice == 1)
		f = caesar;
	else
		f = oddeven;
	cipher(f, s);
	cout << s;
	system("pause");
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
