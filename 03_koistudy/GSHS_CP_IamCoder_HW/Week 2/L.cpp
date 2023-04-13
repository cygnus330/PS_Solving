#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct island
{
    int d;
    int s;
    bool a;
    
    island(int d, int s, bool a): d(d), s(s), a(a) {}
};

int n;
vector<island> v;
int A[510][510];
bitset<510> visited[510];

ll f(int a, int b)
{
    if(visited[a][b])
        return A[a][b];
    visited[a][b] = true;
    
    if(!v[b].a)
        return A[a][b] = 0;
    if(a == n-1)
    {
        if(v[n-1].d - v[n-1].s <= v[b].d)
            return A[a][b] = 1;
        return A[a][b] = 0;
    }
    if(b == n-1)
        return A[a][b] = 0;
    
    int M = max(a, b);
    for(int i=M+1; i<n; i++)
        if(v[a].d + v[a].s >= v[i].d)
            A[a][b] += f(i, b);
    
    for(int i=M+1; i<n; i++)
        if(v[i].d - v[i].s <= v[b].d && v[i].a)
            A[a][b] += f(a, i);
    
    A[a][b] %= 1000;
    return A[a][b];
}

int main()
{
    cin >> n;
    v.assign(n, island(0, 0, 0));
    for(int i=0; i<n; i++)
        cin >> v[i].d >> v[i].s >> v[i].a;
    cout << f(0, 0) << endl;
    
    return 0;
}