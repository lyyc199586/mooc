/*题目内容：

输入5行信息，生成文件A.txt。然后再次打开该文件，为每一行前面加一个行号后显示在屏幕上，行号占据4个字符宽，行号左对齐显示。



输入格式:

5行字符，每行字符中可以有空格，长度小于80



输出格式：

行号占据4个字符宽，行号左对齐显示。



输入样例：

AB

CD

EF

UV

XY



输出样例：

1   AB

2   CD

3   EF

4   UV

5   XY
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ofstream out("A.txt");
    char ch[6][80];
    /*for(int i=0; i<5; i++) {
        cin.getline(ch, 80);
        out<<char(i+49)<<'\t'<<ch<<endl;
    };
    out.close();
    */
    for(int i=0; i<5; i++) {
        cin.getline(ch[i], 80);
    };   
    for(int i=0; i<5; i++) {
        cout<<char(i+49)<<"   "<<ch[i]<<endl;
    };
    system("pause");
    return 0;
}
