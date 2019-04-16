'''
02-线性结构3 Reversing Linked List （25 分)
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤105) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input: # the address of fist node: 00100, the total number of nodes: 6, K = 4
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
'''


def info_input():
    info = input()
    info_list = [n for n in info.split()]
    first_add = info_list[0]
    T = int(info_list[1])  # T: total number of nodes
    K = int(info_list[2])
    return [first_add, T, K]


def list_input(l):
    str_input = input()
    str_list = [n for n in str_input.split()]
    str_list[1] = int(str_list[1])
    l.append(str_list)
    return l


def list_print(l):
    for n in l:
        print("{:s} {:d} {:s}".format(n[0], n[1], n[2]))


def list_sort(l, first_add):
    s = []
    for i in range(len(l)):
        if (first_add == l[i][0]):
            s.append(l[i])
            break
    for i in range(len(l)):
        for j in range(len(l)):
            if (s[i][2] == l[j][0]): # in python3 '==' can be used for strings 
                s.append(l[j])
        continue

    for n in l:
        if n in s:
            continue
        else:
            s.append(n)
    return s


def list_reverse(l, K):
    T = len(l)
    r = []
    for i in range(T // K):
        temp = []
        temp = l[K * i:K * (i + 1)][:]
        temp.reverse()
        for n in temp:
            r.append(n)

    d = len(l) - len(r)
    if d:
        for i in range(T - d, T):
            r.append(l[i])
    return r


if __name__ == "__main__":

    info = []
    info = info_input()
    T = info[1]
    K = info[2]
    first_add = info[0]
    l = []
    for i in range(T):
        l = list_input(l)
    l = list_sort(l, first_add)
    l = list_reverse(l, K)
    list_print(l)
