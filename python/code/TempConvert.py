#TempConvert.py
TempStr = input("input temperature with C or F:")
if TempStr[-1] in ['F', 'f']: # TempStr = input temperature with C or F: C, TempStr[-1] = C
    C = (eval(TempStr[0:-1]) - 32) / 1.8
    print("The temperature is {:.2f}C".format(C))
elif TempStr[-1] in ['C', 'c']:
    F = 1.8 * eval(TempStr[0:-1]) + 32 # eval: "32" -> 32
    print("The temperature is {:.2f}F".format(F))
else:
    print("wrong input")
