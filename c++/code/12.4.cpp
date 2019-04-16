/*
重载矩阵加法运算（20分）
题目内容：

编写一个矩阵类，重载矩阵加法运算。设A，B，C均为m行，
n列的矩阵，要求程序能实现C=A+B的操作。



输入格式:

第一行为矩阵的行数和列数，下面为两个矩阵的元素值



输出格式：

两个矩阵的和。注意，输出的每行元素，行末没有空格。



输入样例：

2 3

1 3 2

4 2 5

2 3 4

3 2 6



输出样例：

3 6 6

7 4 11

提示：由于涉及深浅拷贝的问题，不建议使用动态数组。
*/

#include <iostream>

#define M 10
#define N 10

using namespace std;

class Matrix
{
    int Row;
    int Column;
    int Mat[M][N];

  public:
    void defaultInput(int m, int n)
    {
        Row = m;
        Column = n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                this->Mat[i][j] = 0;
            }
        }
    }
    void Input(int row, int column)
    {
        Row = row;
        Column = column;
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Column; j++)
            {
                cin >> this->Mat[i][j];
            }
        }
    }
    void Show()
    {
        //cout<<Row<<" "<<Column<<endl;
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Column; j++)
            {
                if (j == 0)
                    cout << Mat[i][j];
                else
                    cout << " " << Mat[i][j];
            }
            cout << endl;
        }
    }
    Matrix operator+(Matrix &);
    Matrix operator=(Matrix);
};

Matrix Matrix::operator+(Matrix &m)
{
    Matrix temp;
    temp.defaultInput(this->Row, this->Column);
    //cout<<Row<<" "<<Column<<endl;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Column; j++)
        {
            temp.Mat[i][j] = this->Mat[i][j] + m.Mat[i][j];
        }
    }
    //cout<<Row<<" "<<Column<<endl;
    return temp;
}

Matrix Matrix::operator=(Matrix n)
{
    Row = n.Row;
    Column = n.Column;
    //cout<<Row<<" "<<Column<<endl;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Column; j++)
        {
            this->Mat[i][j] = n.Mat[i][j];
        }
    }
    return (*this);
}

int main()
{
    int row, column;
    Matrix m1, m2, m3;
    cin >> row >> column;
    m1.Input(row, column);
    m2.Input(row, column);
    //m1.Show();
    m3 = m1 + m2;
    m3.Show();
    //(m1+m2).Show();
    return 0;
}
