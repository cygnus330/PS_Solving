import sys
input = lambda : sys.stdin.readline().rstrip()
ip = lambda : int(input())
ips = lambda : input().split()
ipm = lambda : map(int, ips())
ipl = lambda : list(ipm())
sys.setrecursionlimit(100000)

n, q = ipm()
A = [[0 for i in range(n+1)] for j in range(n+1)]

for _ in range(q):
    a, b, c, d, w = ipm()
    for i in range(a-1, c):
        A[i][b-1] += w
        A[i][d] -= w

for i in range(n):
    cnt = 0
    for j in range(n):
        cnt += A[i][j]
        print(cnt, end=" ")
    print()