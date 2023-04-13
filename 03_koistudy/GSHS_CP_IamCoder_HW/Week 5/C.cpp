#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    auto v = vector<vector<int>>(n, vector<int>(m, 0));
    auto q = queue<pair<int, int>>();
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x - 1][y - 1] = 1;
        q.emplace(x - 1, y - 1);
    }
    
    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ex = x + dx[i], ey = y + dy[i];
            if(0 <= ex && ex < n && 0 <= ey && ey < m && !v[ex][ey])
            {
                v[ex][ey] = v[x][y] + 1;
                q.emplace(ex, ey);
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}