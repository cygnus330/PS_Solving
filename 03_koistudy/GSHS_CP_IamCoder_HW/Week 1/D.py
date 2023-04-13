import sys
input = lambda : sys.stdin.readline().rstrip()
ip = lambda : int(input())
ips = lambda : input().split()
ipm = lambda : map(int, ips())
ipl = lambda : list(ipm())
sys.setrecursionlimit(100000)

n, s, cnt = ip(), [], 0
for i in range(n):
    a = ip()
    while len(s) > 0 and s[-1] <= a:
        s.pop()
    cnt += len(s)
    s.append(a)
print(cnt)

