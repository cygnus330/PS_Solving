#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void fastio() // cannot use scanf(), printf() and only 1T
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int mtDist(pii a, pii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int n;
vector<pii> v;
int dist[12][12], A[12][1<<12];

int tsp(int now, int visited)
{
    if(visited == (1<<n) -1)
        return dist[now][0];
    
    if(A[now][visited] != -1)
        return A[now][visited];
    
    A[now][visited] = 1 << 30;
    for(int i=0; i<=n; i++)
    {
        if(dist[now][i] == 0 or (visited >> i)%2)
            continue;
        A[now][visited] = min(A[now][visited], tsp(i, visited | (1<<i)) + dist[now][i]);
    }
    
    return A[now][visited];
}

int main()
{
    fastio();
    cin >> n;
    n++;
    v.assign(n, {0, 0});
    memset(A, -1, sizeof(A));
    for(int i=1; i<n; i++)
        cin >> v[i].first >> v[i].second;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dist[i][j] = mtDist(v[i], v[j]);
    cout << tsp(0, 1) << endl;
    
    return 0;
}