#include <bits/stdc++.h>
//#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

int s, e, n;
vector<int> v;

signed main()
{
    cin >> s >> e >> n;
    v.resize(n);
    for(int &i:v)
        cin >> i;
    
    if(find(all(v), s) != v.end() || find(all(v), e) != v.end())
    {
        cout << -1 << endl;
        exit(0);
    }
    
    queue<int> q;
    int dist[10010];
    memset(dist, -1, sizeof(int) * 10010);
    bitset<10010> visited;
    
    dist[s] = 0;
    visited[s] = true;
    q.emplace(s);
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        int t = 1;
        for(int i = 0; i < 4; i++)
        {
            int a = (x + t + 10000) % 10000;
            int b = (x - t + 10000) % 10000;
            
            if(!visited[a] && find(all(v), a) == v.end())
            {
                dist[a] = dist[x] + 1;
                visited[a] = true;
                q.emplace(a);
            }
            if(!visited[b] && find(all(v), b) == v.end())
            {
                dist[b] = dist[x] + 1;
                visited[b] = true;
                q.emplace(b);
            }
            
            t *= 10;
        }
    }
    cout << dist[e] << endl;
    
    return 0;
}