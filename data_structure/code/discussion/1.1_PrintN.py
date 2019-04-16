'''
递归调用相比循环占用大量空间
'''


def PrintN1(N):
    for i in range(N + 1):
        print("%d" % i)


def PrintN2(N):
    if (N):
        PrintN2(N - 1)
        print("%d" % N)


if __name__ == "__main__":
    PrintN1(1000)
    PrintN2(1000)
