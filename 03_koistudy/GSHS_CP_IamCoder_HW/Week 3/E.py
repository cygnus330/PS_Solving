import sys

input = lambda : sys.stdin.readline().rstrip()
ip = lambda : int(input())
ips = lambda : input().split()
ipm = lambda : map(int, ips())
ipl = lambda : list(ipm())
sys.setrecursionlimit(100000)

import math

def f(n, r):
    if n <= 0:
        return 0
    elif n == 1 and r > 1:
        return 1
    elif r == 3:
        return 2**n - 1
    # A = [(2*f(i, r) + f(n-i, r-1)) for i in range(1, n)]
    # return min(A)
    k = int(n - round(math.sqrt(2*n+1)) + 1)
    return 2*f(k, r) + f(n-k, r-1)

n = ip()
print(f(n, 4))
