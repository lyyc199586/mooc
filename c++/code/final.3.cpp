/*矩形类（10分）
题目内容：

定义一个矩形类，数据成员有宽度、高度和组成矩形的字符，类型分别为整型、整型和字符型，成员函数有void set(int,int,char)设置数据成员的值，void show()显示矩形。若宽度为7，高度为4，字符为“*”，则show()显示的矩形如下（四周为*,中间是空格）：

*******

*     *

*     *

*******

编写主程序，声明矩形类的对象，输入矩形的宽度、高度和组成字符，调用成员函数set()设置矩形参数，调用成员函数show()显示矩形。



输入格式:

两个正整数和一个字符，用空格隔开。



输出格式：

由字符组成的空心矩形。



输入样例：

7 4 *



输出样例：

*******

*     *

*     *

*******



注意：（1）需考虑一些极端情况，（2）要用类实现。（3）可能由于显示格式的问题，题目页面的矩形会错位。只要按格式要求输出。如对样例来说，第2行，两头是“*”，中间是5个空格。,
*/

#include <iostream>

using namespace std;

class Rectangle{
    int height;
    int width;
    char mark;
public:
    void set(int h,int w,char m){
        height = h;
        width = w;
        mark = m;
    };
    void show(){
        for (int i = 0; i < height;i++){
            if(i==0||i==(height-1)){
                for (int j = 0; j < width;j++){
                    cout << mark;
                }
                cout << endl;
            }
            else{
                cout << mark;
                for (int j = 1; j < width-1;j++){
                    cout << ' ';
                }
                if(width==1){cout << endl;}
                else{cout << mark << endl;}
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int h;
    int w;
    char m;
    cin >> w >> h >> m;
    Rectangle r1;
    r1.set(h, w, m);
    r1.show();
    system("pause");
    return 0;
}
