/*抽象宠物类的实现（20分）
题目内容：

定义抽象宠物类Pet，其中数据成员包括：名字，年龄和颜色；
成员函数包括：构造函数；获取成员数据值的函数；
纯虚函数Speak和纯虚函数GetInfo;
定义Pet的派生类Cat和Dog，其中Speak函数分别显示猫和狗的叫声,
而GetInfo函数分别输出Cat和Dog的属性。主函数中定义Pet指针变量，
分别指向动态生成的Cat和Dog对象，并通过指针分别调用GetInfo函数
和Speak函数，观察并分析输出结果。



输入格式:

猫和狗的信息



输出格式：

请参考输出样例，严格遵照格式要求输出，
建议直接复制样例中的部分文字粘贴进自己的代码中.
(冒号是英文冒号，冒号后无空格)



输入样例：

mikey 2 blue
benben 1 black



输出样例：

猫的名字:mikey

猫的年龄:2

猫的颜色:blue

猫的叫声:miao!miao!

狗的名字:benben

狗的年龄:1

狗的颜色:black

狗的叫声:wang!wang!
*/

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class Pet{
    char Name[10];
    char Color[10];
    int Age;
public:
    Pet(char* name, char* color, int age){
        strcpy(Name, name);
        strcpy(Color, color);
        Age = age;
    }
    void GetName() {cout<<Name<<endl;}
    void GetColor() {cout<<Color<<endl;}
    void GetAge() {cout<<Age<<endl;}
    virtual void Speak() = 0;
    virtual void GetInfo() = 0;
};

class Cat:public Pet{
public:
    Cat(char* name, char* color, int age):Pet(name,color,age){}
    void Speak(){
        cout<<"miao!miao!"<<endl;
    }
    void GetInfo(){
        cout<<"猫的名字:";
        GetName();
        cout<<"猫的年龄:";
        GetAge();
        cout<<"猫的颜色:";
        GetColor();
        cout<<"猫的叫声:";
        Speak();
    }
};

class Dog:public Pet{
public:
    Dog(char* name, char* color, int age):Pet(name,color,age){}
    void Speak(){
        cout<<"wang!wang!"<<endl;
    }
    void GetInfo(){
        cout<<"狗的名字:";
        GetName();
        cout<<"狗的年龄:";
        GetAge();
        cout<<"狗的颜色:";
        GetColor();
        cout<<"狗的叫声:";
        Speak();
    }
};

int main()
{
    char name[10];
    char color[10];
    int age;
    cin>>name>>age>>color;
    Cat c1(name, color, age);
    cin>>name>>age>>color;
    Dog d1(name, color, age);
    c1.GetInfo();
    d1.GetInfo();
    system("pause");
    return 0;
}
