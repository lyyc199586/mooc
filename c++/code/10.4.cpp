/*��Ʋ�����һ����Բ�ࣨ20�֣�
��Ŀ���ݣ�

��Ʋ�����һ����ΪEllipse����Բ�࣬������ΪԲ�����꼰������Ͷ̰���ĳ��ȡ����һ�����캯����Ellipse(int,int,double,double)������Щ���Խ��г�ʼ������ͨ����Ա�����������Բ�������double
Area()����

S����Բ�����=PI(Բ����)��a�������ᣩ��b���̰��ᣩ
����PIȡ3.14

�����ʽ:

Բ�����ꡢ������Ͷ̰���ĳ���



�����ʽ��

��Բ�����

����������

1 1 1 2

���������

6.28
*/
#include <iostream>

using namespace std;

class Ellipse
{
    int x;
    int y;
    double major; // semi-major axis
    double minor; // semi-minor axis
public:
    Ellipse(int x, int y, double major, double minor)
    {
        this->x = x;
        this->y = y;
        this->major = major;
        this->minor = minor;
    }
    double Area()
    {return 3.14*major*minor;}
};

int main()
{
    int x,y;
    double a,b;
    cin>>x>>y>>a>>b;
    Ellipse e1(x, y, a, b);
    cout<<e1.Area()<<endl;
    return 0;
}
