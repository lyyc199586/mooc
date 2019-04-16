#include <iostream>
#include <string.h>

using namespace std;

class Person
{
    char name[20];
    int age;
    char sex;
public:
    Person()
    {
        strcpy(name, "XXX");
        age = 0;
        sex = 'm';
    }
    void Register(char *, int, char);
    void showme();
    ~Person(){cout<<"Now destroying the instance of Person"<<endl;};
};

void Person::Register(char *n, int a, char s)
{
    strcpy(name, n);
    age = a;
    sex = s;
}

void Person::showme()
{
    cout<<name<<" "<<age<<" "<<sex<<endl;
}

int main()
{
    Person *p1 = new Person;
    Person *p2 = new Person;
    char n[20];
    int a;
    char s;
    cin>>n>>a>>s;
    cout<<"person1:";
    p1->showme();
    cout<<"person2:";
    p2->showme();
    p1->Register(n, a, s);
    *p2 = *p1;
    cout<<"person1:";
    p1->showme();
    cout<<"person2:";
    p2->showme();
    delete p1;
    delete p2;
    return 0;
}
