A = [i for i in range(n+1)]
    def find(a):
        if A[a] == a:
            return a
        A[a] = find(A[a])
        return A[a]
    def union(a, b):
        if find(a) == find(b):
            return
        A[find(b)] = find(a)