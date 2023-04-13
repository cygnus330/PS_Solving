#include <bits/stdc++.h>
//#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

signed main()
{
    int n, m;
    vector<pair<int, vector<int>>> v;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.emplace_back(0, vector<int>(t));
        for(int &j:v.back().second)
            cin >> j;
    }
    
    vector<queue<int>> q(m + 1, queue<int>());
    vector<vector<int>> b(m + 1, vector<int>(0));
    vector<pii> s;
    
    for(int i = 0; i < n; i++)
        q[v[i].second[v[i].first++]].push(i);
    
    while(true)
    {
        for(auto &i:s)
            q[i.first].emplace(i.second);
        s.assign(0, pii(0, 0));
        
        {
            unsigned int cnt = 0;
            for(int i = 1; i <= m; i++)
                cnt += q[i].size();
            if(cnt == 0)
            {
                for(int i = 1; i <= m; i++)
                {
                    cout << b[i].size();
                    for(int &j : b[i])
                        cout << " " << j;
                    cout << endl;
                }
                exit(0);
            }
        }
        
        for(int i = 1; i <= m; i++)
        {
            if(q[i].empty())
                continue;
            
            int x = q[i].front();
            q[i].pop();
            b[i].emplace_back(x + 1);
            
            if(v[x].second.size() <= v[x].first)
                continue;
            
            s.emplace_back(v[x].second[v[x].first++], x);
        }
    }
    
    return 0;
}