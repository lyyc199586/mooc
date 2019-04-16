'''
02-线性结构2 一元多项式的乘法与加法运算 （20 分)
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
'''


def ReadPoly():
    '''
    input a polynomial P = [[c0, e0], [c1, e1], ...]
    '''
    P = []
    number = []
    number = input()
    nu = [int(n) for n in number.split()]
    length = nu[0]
    for i in range(length):
        P.append([nu[2 * i + 1], nu[2 * i + 2]])
    while [0, 0] in P:
        P.remove([0, 0])
    return P


def PrintPoly(P):
    '''
    print a polynomial P = "c0 e0 ... cn en"
    '''
    while [0, 0] in P: # 去除不必要的0元素以免造成未知麻烦
        P.remove([0, 0])
    if (len(P) == 0): # P = []时的特例
        print('0 0')
    else:
        for i in range(len(P)):
            if (i == 0):
                print("{:d} {:d}".format(P[i][0], P[i][1]), end='')
            else:
                print(" {:d} {:d}".format(P[i][0], P[i][1]), end='')
        print()


def Add(P1, P2):
    '''
    add two polynomials
    '''
    i = j = 0
    s = 0
    P = [[0, 0]]
    while (i < len(P1) and j < len(P2)):  # and/or in python!
        if (P1[i][1] == P2[j][1]):
            s = P1[i][0] + P2[j][0]
            if (s != 0):
                P.append([s, P1[i][1]])
            i += 1
            j += 1
            continue
        elif (P1[i][1] > P2[j][1]):
            P.append([P1[i][0], P1[i][1]])
            i += 1
            continue
        else:
            P.append([P2[j][0], P2[j][1]])
            j += 1
            continue

    if (i < len(P1)):
        for m in range(i, len(P1)):
            P.append([P1[m][0], P1[m][1]])
    if (j < len(P2)):
        for n in range(j, len(P2)):
            P.append([P2[n][0], P2[n][1]])
    return P


def Mult(P1, P2):
    '''
    multiply two polynomials
    这里我用了将乘法运算转换成加法运算的方法
    '''
    PP = [[0, 0]]
    for i in range(len(P1)):
        temp = [[0, 0]]
        for j in range(len(P2)):
            temp.append([P1[i][0] * P2[j][0], P1[i][1] + P2[j][1]])
        PP = Add(PP, temp)
    return PP


if __name__ == "__main__":
    P1 = ReadPoly()
    P2 = ReadPoly()
    PP = Mult(P1, P2)
    PrintPoly(PP)
    PM = Add(P1, P2)
    PrintPoly(PM)
