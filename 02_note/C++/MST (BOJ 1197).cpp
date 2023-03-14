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

struct st
{
    int d, s, e;
    
    bool operator < (st a)
    {
        return d < a.d;
    }
};

int v, e;
vector<pii> mst;
vector<st> ed;

// union-find
int p[10010];
int Find(int a)
{
    if(p[a] == a)
        return a;
    return p[a] = Find(p[a]);
}
bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b)
        return 0;
    
    p[a] = b;
    return 1;
}

int main()
{
    cin >> v >> e;
    iota(p, p+10010, 0);
    for(int i=0; i<e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ed.push_back({c, a, b});
    }
    sort(all(ed));
    
    int cnt = 0;
    for(st &i:ed)
        if(Union(i.s, i.e))
            cnt += i.d;
    cout << cnt << endl;
    
    return 0;
}