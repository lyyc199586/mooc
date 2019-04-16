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
