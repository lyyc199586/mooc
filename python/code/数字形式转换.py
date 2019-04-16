a = ["零","一","二","三","四","五","六","七","八","九"] #不用这么写，直接写成字符串就行
input_A = str(input(""))
arr = []
arr = [int(n) for n in input_A]
for i in range(len(input_A)):
    print(a[int(input_A[i])], end='')


# 答案
template = "零一二三四五六七八九"

s = input()
for c in s:
    print(template[eval(c)], end="")