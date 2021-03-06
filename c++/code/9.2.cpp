//设计Dog类（20分）
//题目内容：
//
//设计一个Dog类，包含name、age、sex和weight等属性以及对这些属性操作的方法。实现并测试这个类。
//根据类的封装性要求，把name、age、sex和weight声明为私有的数据成员，编写公有成员函数setdata()
//对数据进行初始化，GetName()、GetAge()、GetSex()和GetWeight()获取相应属性。初始化数据由用户输入。
//
//输入格式 :
//
//Dog类对象的初始化数据
//
//输出格式：
//
//根据Dog类对象的初始化数据输出一句话，请严格按照格式输出，句末有点号。
//
//输入样例：
//
//ahuang 3 m 2.4
//
//输出样例：
//
//It is my dog.
//
//Its name is ahuang.
//
//It is 3 years old.
//
//It is male.
//
//It is 2.4 kg.

#include <iostream>
#include <string.h>

using namespace std;

class Dog {
private:
	char name[10];
	int age;
	char sex;
	float weight;
public:
	void setdata(const char *n,int a,char s, float w);
	void GetName();
	void GetAge();
	void GetSex();
	void GetWeight();
};



int main()
{
	char n[10];
	int a;
	char s;
	float w;
	Dog dog;
	cin >> n >> a >> s >> w;
	dog.setdata(n, a, s, w);
	cout << "It is my dog." << endl;
	dog.GetName();
	dog.GetAge();
	dog.GetSex();
	dog.GetWeight();
	system("pause");
	return 0;
}

void Dog::setdata(const char *n, int a, char s, float w)
{
	strcpy_s(name, n);
	age = a;
	sex = s;
	weight = w;
}

void Dog::GetName()
{
	cout << "Its name is " << name << '.' << endl;
}

void Dog::GetAge()
{
	cout << "It is " << age << " years old." << endl;
}

void Dog::GetSex()
{
	if (sex == 'm') cout << "It is male." << endl;
	else cout << "It is female." << endl;
}

void Dog::GetWeight()
{
	cout << "It is " << weight << " kg." << endl;
}
