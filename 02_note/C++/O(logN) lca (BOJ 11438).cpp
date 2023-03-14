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

int n, m;
vector<int> ed[100010];
int depth[100010], mo[100010][22];

int f(int a, int b)
{
    if(depth[a] < depth[b])
        swap(a, b);
    
    int dDepth = depth[a] - depth[b];
    for(int i=21; i>=0; i--)
        if(dDepth & (1 << i))
            a = mo[a][i];
    
    if(a == b)
        return a;
    
    for(int i=21; i>=0; i--)
        if(mo[a][i] != mo[b][i] && mo[a][i])
        {
            a = mo[a][i];
            b = mo[b][i];
        }
    a = mo[a][0];
    
    return a;
}

void d()
{
    bitset<100010> visited;
    stack<int> s;
    depth[1] = 1;
    visited[1] = 1;
    s.push(1);
    
    while(!s.empty())
    {
        int a = s.top();
        s.pop();
        for(int &n:ed[a])
            if(!visited[n])
            {
                visited[n] = 1;
                depth[n] = depth[a] + 1;
                mo[n][0] = a;
                s.push(n);
            }
    }
}

int main()
{
    fastio();
    
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        ed[a].emplace_back(b);
        ed[b].emplace_back(a);
    }
    d();
    
    for(int i=1; i<21; i++)
        for(int j=1; j<=n; j++)
            mo[j][i] = mo[mo[j][i-1]][i-1];
    
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << f(a, b) << endl;
    }
    
    return 0;
}