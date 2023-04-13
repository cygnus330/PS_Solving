#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n + 2, 0);
    queue<int> q;
    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        v[a] = 1;
        q.push(a);
    }
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        if(x > 1 && !v[x - 1])
        {
            v[x - 1] = v[x] + 1;
            q.emplace(x - 1);
        }
        if(x < n && !v[x + 1])
        {
            v[x + 1] = v[x] + 1;
            q.emplace(x + 1);
        }
    }
    
    for(int i = 1; i <= n; i++)
        cout << v[i] << " ";
    
    return 0;
}