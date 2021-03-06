// 8.6.cpp : 十进制点分IP转换为32位二进制IP
//题目内容：

//编写程序，将十进制点分的IP转换为32位二进制IP地址。程序要能验证输入的十进制点分ＩＰ地址的合法性。用户输入的ＩＰ不和法时，输出"data error"。
//
//
//
//请使用模块化程序设计的思想，将功能模块编写成函数。通过指针传递参数，操作数据，返回结果。在主函数中输入IP地址，调用函数进行合法性验证和转换，在主函数中输出32位二进制IP。
//
//
//
//输入格式:
//
//十进制点分IP地址(英文句点)
//
//
//
//输出格式：
//
//32位二进制数（二进制字符串）
//
//
//
//输入样例：
//
//202.151.96.33
//
//
//
//输出样例：
//
//11001010100101110110000000100001
//
//
//
//提示：十进制转换为二进制。对整数部分，除2取余，直到商为0。例如
//
//13/2=6.....1(低位)
//
//6/2=3......0
//
//3/2=1......1
//
//1/2=0......1
//
//转换后的二进制数位1101


#include <iostream>
#include <string.h>

using namespace std;

bool correct(char *str) {
	int num = 0;
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (str[i] == '.') {
			num++;
		}
	}
	return(num == 3 ? true : false);
}

void bin2dec(int dec) {
	int remain = 1;
	int i = 7;
	char str2[9] = "00000000";//8 digits binary number
	while (dec != 0) {
		remain = dec % 2;
		dec = dec / 2;
		str2[i] = char(remain + 48);
		i--;
	}
	cout << str2;
}

void transfer(char *str) 
{
	int length = strlen(str);
	int digit = 0;
	int number = 0;
	for (int i = 0; i <= length;) {
		if (str[i] != '.'&&i != length) {
			digit++;
			i++;
		}
		else {//str[i] == '.'
			for (int j = i - digit; j < i; j++) {
				number = 10 * number + int(str[j] - 48);
			}//'0' -> 48, 
				bin2dec(number);
				number = 0;
				i++;
				digit = 0;
		}
	}
}

int main()
{
	char str1[100];
	cin.getline(str1, 100);
	if (correct(str1)) {
		transfer(str1);
	}
	else cout << "data error";
	return 0;
}

