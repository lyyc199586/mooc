/*公有继承中派生类Student对基类Person成员的访问（20分）
题目内容：

已知基类Person的定义如下：
class Person
{
	char Name[20];
	char Sex;
	int
		Age;
public:
	void Register(char *name, int age, char sex);
	void
		ShowMe();
};
请通过继承的方法建立一个派生类Student，其中
1．新增的数据成员有：
int
Number;
char ClassName[10];
2．新增的成员函数有：
void RegisterStu(char
	*classname, int number, char *name, int age, char sex)

	//对数据成员赋值，并使用基类的Register
	void
	ShowStu() //显示数据成员信息，并使用基类的ShowMe
	在主程序中建立一个派生类对象，利用已有的成员函数分别显示派生类对象和基类对象的数据成员。



	输入格式 :

学生的班级、学号、姓名、年龄和性别



输出格式：

先输出派生类对象的数据成员，依次为 学号、班级、姓名、年龄和性别

再输出基类的数据成员，依次为姓名、年龄和性别



输入样例：

计算机51 85071011 张弓长 18 m



输出样例：

85071011 计算机51 张弓长 18 m
张弓长 18 m
*/

#include <iostream>

using namespace std;

class Person
{
	char Name[20];
	char Sex;
	int Age;
public:
	void Register(char *name, int age, char sex) {
		strcpy_s(Name, name);
		Age = age;
		Sex = sex;
	}
	void ShowMe() {
		cout << Name << " " << Age << " " << Sex;
	}
};

class Student:public Person
{
	int Number;
	char ClassName[10];
public:
	void RegisterStu(char *classname, int number, char *name, int age, char sex) {
		Person::Register(name, age, sex);
		strcpy_s(ClassName, classname);
		Number = number;
	}
	void ShowStu() {
		cout << Number << " " << ClassName << " ";
		Person::ShowMe();
	}

};

int main()
{
	char classname[10], name[10];
	int id, age;
	char sex;
	Student s1;
	cin >> classname >> id >> name >> age >> sex;
	s1.RegisterStu(classname, id, name, age, sex);
	s1.ShowStu();
	cout << endl;
	s1.ShowMe();
	return 0;
}

