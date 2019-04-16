'''
01-复杂度2 Maximum Subsequence Sum （25 分）
Given a sequence of K integers { N1, N​2, ..., NK}. A continuous subsequence is defined to be { N​i, Ni+1, ..., N​j} where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
'''

if __name__ == '__main__':
    N = int(input())
    A = [int(n) for n in input().split()]
    leftmax = 0
    rightmax = 0
    left_temp = A[0]
    right_temp = A[0]
    ThisSum = MaxSum = 0
    all_negative = True
    begin_again = False
    for i in range(N):
        ThisSum += A[i]

        if (A[i] >= 0):
            all_negative = False

        if (begin_again):
            left_temp = A[i]
            right_temp = A[i]
            begin_again = False
        else:
            right_temp = A[i]
            
        if (ThisSum > MaxSum):
            MaxSum = ThisSum
            leftmax = left_temp
            rightmax = right_temp

        elif (ThisSum < 0):
            ThisSum = 0
            begin_again = True

    if (MaxSum == 0):
        if (all_negative):
            print("0 %d %d" % (A[0], A[N - 1]))
        else:
            print("0 0 0")
    else:
        print("%d %d %d" %(MaxSum, leftmax, rightmax))
