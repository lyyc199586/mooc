// 6.3.cpp : 编写重载函数来打印字符串
//题目内容：
//编写函数 print_spaced 来打印字符串，要求打印出的字符串每个字母之间都有一个空格。要求编写两个同名函数，一个支持字符数组输入，另一个支持string类型输入。然后编写main函数测试这两个函数，第一个使用字符数组输入，第二个使用string类型输入。
//
//输入格式 :
//两个字符串，长度不超过100，只包含英文大小写字母，不含其他字符。
//
//输出格式：
//经间隔空格处理后的两个字符串，两个字符串分居两行。注意字符串的最后一个字母后面没有空格。
//
//输入样例：
//news
//final
//
//输出样例：
//n e w s
//f i n a l
//-------------------- -
//作者：Conan_Cui
//来源：CSDN
//原文：https ://blog.csdn.net/qq_28833741/article/details/52752020 
//版权声明：本文为博主原创文章，转载请附上博文链接！

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void print_spaced(char str[]);
void print_spaced(string &str);

int main()
{
	char str[100];
	cin.getline(str, 100);
	string str2;
	getline(cin, str2);

	print_spaced(str2);
	print_spaced(str);

	cout << str << endl;
	cout << str2;
//	system("pause");
	return 0;
}

void print_spaced(char str[]) {
	int length = strlen(str);
	char temp[100];
	for (int i = 0; i < length; i++) {
		temp[i] = str[i];
	}

	int j = 0;
	for (int i = 0; i < length; i++) {
		str[j] = temp[i];
		j++;
		if (i != length - 1) {
			str[j] = 32; //32=' '
			j++;
		}
	}
	str[j] = 0;//0='\0'
}

void print_spaced(string &str) {
	int length = str.length();
	string temp;
	for (int i = 0; i < length; i++) {
		temp = temp + str[i];
		if (i != length - 1) {
			temp = temp + ' ';
		}
	}
	str = temp;
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
