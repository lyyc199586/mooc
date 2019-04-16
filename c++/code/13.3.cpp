/*读写文件并转换字符（20分）
题目内容：

编写一个程序，从键盘输入一行字符（可包含各种字符，遇回车符结束），写入到文件a1.txt中；再从a1.txt中读出文件内容，将其中的小写字母转换成大写字母后显示在屏幕上。



提示：输入带空格的字符串，用cin.getline()。



输入格式:

一个字符串，中间可能有大写或小写字母、空格、数字以及其他标点符号。长度小于80。



输出格式：

输出同输入内容相同的字符串，其中小写字母变成大写字母。



输入样例：

We are students from Xi'an Jiaotong University.



输出样例：

WE ARE STUDENTS FROM XI'AN JIAOTONG UNIVERSITY.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char ch[80];
    cin.getline(ch, 80);
    /*
    ofstream out("a1.txt");
    out<<ch;
    out.close();
    ifstream in("a1.txt");
    in.getline(ch, 80);
    */
    for(int i=0; i<80; i++){
        if(ch[i]<='z'&&ch[i]>='a'){
            ch[i] -= 32;
        }
        if(ch[i]=='\0') {break;}
    }
    cout<<ch;
    system("pause");
    return 0;
}
