'''
循环和递归算法的效率（时间上）差一个数量级
f(x) = 1 + Sum_i^100 x**i/i, x = 1.1
'''


import time


def f1(n):
    s = 1.1 / n
    for i in range(n - 1, 0, -1):
        s = s * 1.1 + 1.0/i
    s = s * 1.1 + 1
    return s


def f2(n):
    s = 0
    for i in range(1, n + 1):
        s += (1.1 ** i) / i
    return s


if __name__ == "__main__":
    start = time.time()
    for i in range(20000):
        f1(100)
    print(time.time() - start)
    start = time.time()
    for i in range(20000):
        f2(100)
    print(time.time() - start)
