#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void sync() // cannot use scanf(), printf() and only single-core
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
vector<int> v[50010];
bool visited[50010];
int p[50010], d[50010];

int lca(int a, int b)
{
    if(d[a] > d[b])
        swap(a, b);
    //make to (b is deeper)
    
    while(d[a] != d[b])
        b = p[b];
    //make to (depth is same)
    
    while(a != b)
    {
        a = p[a];
        b = p[b];
    }
    // make to (same)
    
    return a;
}

int main()
{
    sync();
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    queue<int> q;
    visited[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        
        for(int i=0; i<v[a].size(); i++)
            if(!visited[v[a][i]])
            {
                d[v[a][i]] = d[a] + 1;
                visited[v[a][i]] = 1;
                p[v[a][i]] = a;
                q.push(v[a][i]);
            }
    }
    
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    
    return 0;
}