/*��ƴ����캯����Dog�ࣨ20�֣�
��Ŀ���ݣ�

���һ��Dog�࣬����name��age��sex��weight�����ԣ����в����Ĺ��캯���ж����ݳ�Ա���г�ʼ����

���г�Ա�����У�GetName()��GetAge()��GetSex()��GetWeight()�ɻ�ȡ���֡����䡢�Ա�����ء���д��Ա����speak()
��ʾ���Ľ�������д�����������빷�����֡����䡢�Ա�����أ�����Dog���������������ͨ�����캯����ʼ������ͨ����Ա������ȡ�������Բ���ʾ������



�����ʽ:

������Ϣ



�����ʽ��

������Ϣ����ӽ���



����������

Tom 4 m 2.4



���������

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
