from random import randint
import time
import matplotlib.pyplot as plt

def evaluate_n2(A, x):
    # A[0]*x**(n-1) + A[1]*x**(n-2) + ... + A[n-1]
    n = len(A)
    ans = 0
    for i in range(n):
        ans += A[i]*x**(n-1-i)
    return ans

def evaluate_n(A, x):
    n = len(A)
    ans = 0
    temp = 1
    for i in range(n):
        ans += A[n-1-i]*temp
        temp *= x
    return ans

if __name__=='__main__':
    N = []
    O_n = []
    O_n2 = []

    for n in range(1, 100000, 10000):
        N.append(n)
        A = []
        for i in range(n):
            A.append(randint(-999, 999))
        x = 2

        before = time.clock()
        ans2 = evaluate_n2(A, x)
        O_n2.append(time.clock()-before)

        before = time.clock()
        ans1 = evaluate_n(A, x)
        O_n.append(time.clock()-before)

        print(ans1==ans2)

    plt.xlabel("n")
    plt.ylabel("t")
    plt.plot(N, O_n, label="O(n)")
    plt.plot(N, O_n2, label="O(n^2)")
    plt.legend()
    plt.show()