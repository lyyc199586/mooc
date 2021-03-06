/*虚函数实现多态性（20分）
题目内容：

定义宠物类Pet，包含虚函数Speak，显示如下信息“How does a pet speak?”;
定义公有派生类Cat和Dog，其Speak成员函数分别显示：“miao! miao!”和“wang! wang!”。
主函数中定义Pet，Cat和Dog对象，再定义Pet指针变量，分别指向Pet，Cat和Dog对象，
并通过指针调用Speak函数，观察并分析输出结果。



输入格式:

不需要输入



输出格式：

各类调用Speak函数输出的结果



输入样例：





输出样例：

How does a pet speak?

miao!miao!

wang!wang!*/

#include <iostream>

using namespace std;

class Pet{
public:
    virtual void Speak(){
        cout<<"How does a pet speak?"<<endl;
    }
};

class Cat:public Pet{
public:
    void Speak(){
        cout<<"miao! miao!"<<endl;
    }
};

class Dog:public Pet{
public:
    void Speak(){
        cout<<"wang! wang!"<<endl;
    }
};

int main()
{
    Pet p1;
    Cat c1;
    Dog d1;
    Pet* p2;
    p2 = &p1;
    p2->Speak();
    p2 = &c1;
    p2->Speak();
    p2 = &d1;
    p2->Speak();
    return 0;
}