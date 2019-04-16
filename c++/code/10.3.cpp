/*设计带构造函数的Dog类（20分）
题目内容：

设计一个Dog类，包含name、age、sex和weight等属性，在有参数的构造函数中对数据成员进行初始化。

公有成员函数有：GetName()、GetAge()、GetSex()和GetWeight()可获取名字、年龄、性别和体重。编写成员函数speak()
显示狗的叫声。编写主函数，输入狗的名字、年龄、性别和体重；声明Dog对象并用输入的数据通过构造函数初始化对象，通过成员函数获取狗的属性并显示出来。



输入格式:

狗的信息



输出格式：

狗的信息，外加叫声



输入样例：

Tom 4 m 2.4



输出样例：

Tom

4

m

2.4

Arf!Arf!
*/

#include <iostream>
#include <string.h>

using namespace std;

class Dog
{
    char name[20];
    int age;
    char sex;
    float weight;
public:
    Dog(char *_name, int age, char sex, float weight)
    {
        strcpy(name, _name);
        this->age = age;
        this->sex = sex;
        this->weight = weight;
    }
    void GetName(){cout<<name<<endl;}
    void GetAge(){cout<<age<<endl;}
    void GetSex(){cout<<sex<<endl;}
    void GetWeight(){cout<<weight<<endl;}
    void speak(){cout<<"Arf!Arf!"<<endl;}
};

int main()
{
    char n[20];
    int a;
    float w;
    char s;
    cin>>n>>a>>s>>w;
    Dog d1(n, a, s, w);
    d1.GetName();
    d1.GetAge();
    d1.GetSex();
    d1.GetWeight();
    d1.speak();
    return 0;
}
