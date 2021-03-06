/*从Student类和Teacher类多重派生Graduate类（20分）
题目内容：

已知基类Person定义如下：
class Person
{
	char Name[10];
	char Sex[10];
	int Age;
public:
	void Register(char *name, int age, char *sex);
	void ShowMe();
};
请通过继承的方法建立两个派生类，其中
派生类Teacher：
1．新增的数据成员有：
char Dept[20];
int Salary;
2.新增的成员函数有：
Teacher(char *name, int age, char *sex, char *dept, int salary);
void Show() //显示新增数据成员
派生类Student：
1．新增的数据成员有：
char ID[12];
char Class[12];
2.新增的成员函数有：
Student(char *name, int age, char *sex, char *ID, char *Class);
void Show()//显示新增数据成员
请通过继承的方法从Teacher和Student中建立派生类Graduate，其中
1.新增的成员函数有：
Graduate(char *name, int age, char *sex, char *dept, int salary, char *id, char *classid);
2.重写的成员函数有：
void ShowMe()//显示数据成员，要求调用基类的Show和ShowMe
在主程序中建立一个派生类Graduate的对象，利用成员函数显示对象的数据成员。




输入格式 :

Graduate对象的初始化信息



输出格式：

按照输出样例格式输出Graduate对象的信息



输入样例：

李木子 22 f 电信学院 2300 04035003 硕401



输出样例：

班级 硕401
学号 04035003
姓名 李木子
性别 女
年龄 22
工作单位 电信学院
月薪 2300
*/

#include <iostream>

using namespace std;

class Person 
{
	char Name[10];
	char Sex;
	int Age;
public:
	void Register(char *name, int age, char sex) {
		strcpy(Name, name);
		Age = age;
		Sex = sex;
	}
	void ShowMe() {
		cout << "姓名 " << Name << endl;
		switch (Sex)
		{
		case 'm':cout << "性别 男" << endl; break;
		case 'f':cout << "性别 女" << endl; break;
		}
		cout << "年龄 " << Age << endl;
	}
};

class Teacher :public Person
{
	char Dept[20];
	int Salary;
public:
	Teacher(char*, int, char, char*, int);
	void Show() {
		cout << "工作单位 " << Dept << endl;
		cout << "月薪 " << Salary << endl;
	}
};
Teacher::Teacher(char *name, int age, char sex, char *dept, int salary) {
	Register(name, age, sex);
	strcpy(Dept, dept);
	Salary = salary;
}

class Student :public Person
{
	char ID[12];
	char Class[12];
public:
	Student(char*, int, char, char*, char*);
	void Show() {
		cout << "班级 " << Class << endl;
		cout << "学号 " << ID << endl;
	}
};

Student::Student(char *name, int age, char sex, char *id, char *classname) {
	Register(name, age, sex);
	strcpy(ID, id);
	strcpy(Class, classname);
}

class Graduate :public Teacher, public Student
{
public:
	Graduate(char *name, int age, char sex, char *dept, int salary, char *id, char *classid) :
		Student(name, age, sex, id, classid), Teacher(name, age, sex, dept, salary){}
	void ShowMe() {
		Student::Show();
		Student::ShowMe();
		Teacher::Show();
	}
};


int main()
{
	char name[10];
	int age;
	char sex;
	char dept[20];
	int salary;
	char id[12];
	char classid[12];
	cin >> name >> age >> sex >> dept >> salary >> id >> classid;
	Graduate g1(name, age, sex, dept, salary, id, classid);
	g1.ShowMe();
	return 0;

}

