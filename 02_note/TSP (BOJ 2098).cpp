#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
void sync() // scanf() printf() X , only single-core
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//TSP, BOJ 2098
int n, dist[17][17], A[17][1<<16];

int tsp(int rn, int visited)
{
    if(visited == (1<<n)-1)
    {
        if(dist[rn][0] == 0)
            return 1 << 28;
        else
            return dist[rn][0];
    }
    
    if(A[rn][visited] != -1)
        return A[rn][visited];
    
    A[rn][visited] = 1 << 26;
    for(int i=0; i<n; i++)
    {
        if((dist[rn][i] == 0) || ((visited >> i)%2))
            continue;
        
        A[rn][visited] = min(A[rn][visited], tsp(i, visited | (1 << i)) + dist[rn][i]);
    }
    
    return A[rn][visited];
}

int main()
{
    sync();
    cin >> n;
    memset(A, -1, sizeof(A));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> dist[i][j];
    cout << tsp(0, 1) << endl;
    
    return 0;
}
