import sys
input = lambda : sys.stdin.readline().rstrip()
ip = lambda : int(input())
ips = lambda : input().split()
ipm = lambda : map(int, ips())
ipl = lambda : list(ipm())
sys.setrecursionlimit(100000)

n, cnt = ip(), 0
for i in range(1, n+1, 2):
    cnt += 1

if cnt%2 == 0:
    print(sum(i for i in range(1, n+1, 2)))
else:
    print(sum(i for i in range(2, n+1, 2)))