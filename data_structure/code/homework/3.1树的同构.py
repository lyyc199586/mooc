'''
03-树1 树的同构 （25 分)
给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。
现给定两棵树，请你判断它们是否是同构的。

输入格式:
输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。

输出格式:
如果两棵树是同构的，输出“Yes”，否则输出“No”。

输入样例1（对应图1）：
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
输出样例1:
Yes
输入样例2（对应图2）：
8
B 5 7
F - -
A 0 3
C 6 -
H - -
D - -
G 4 -
E 1 -
8
D 6 -
B 5 -
E - -
H - -
C 0 2
G - 3
F - -
A 1 4
输出样例2:
No
'''


class Node:
    def __init__(self, element):
        self.element = element
        self.left = None  # child1
        self.right = None  # child2


class Tree:
    def __init__(self):
        self.root = None
        self.tree = None  

    def build(self, tree=[]):
        N = int(input())
        T = tree
        if N:
            check = [0] * N
            for i in range(N):
                input_str = input()
                element = input_str[0]
                T.append(Node(element))
                cl = input_str[2]
                cr = input_str[-1]
                if cl != '-':
                    T[i].left = int(cl)
                    check[T[i].left] = 1
                else:
                    T[i].left = None
                if cr != '-':
                    T[i].right = int(cr)
                    check[T[i].right] = 1
            for i in range(N):
                if check[i] == 0:
                    root = i
                    break
        tree = T
        return root


def Isomorphic(R1, R2):
    if R1 == None and R2 == None:
        return 1
    elif (R1 == None and R2 != None) or (R1 != None and R2 == None):
        return 0
    elif T1[R1].element != T2[R2].element:
        return 0
    elif T1[R1].left == None and T2[R2].left == None:
        return Isomorphic(T1[R1].right, T2[R2].right)
    elif ((T1[R1].left != None) and (T2[R2].left != None)) and (T1[T1[R1].left].element == T2[T2[R2].left].element):
        return (Isomorphic(T1[R1].left, T2[R2].left) and Isomorphic(T1[R1].right, T2[R2].right))
    else:
        return (Isomorphic(T1[R1].left, T2[R2].right) and Isomorphic(T1[R1].right, T2[R2].left))


if __name__ == "__main__":
    T1 = []
    T2 = []
    R1 = Tree.build(T1)
    R2 = Tree.build(T2)
    if Isomorphic(R1, R2):
        print("Yes")
    else:
        print("No")
