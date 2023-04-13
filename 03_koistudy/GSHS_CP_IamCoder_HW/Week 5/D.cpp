#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    
    pair<int, int> s, e;
    auto v = vector<string>(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == 'S')
                s = pair<int, int>(i, j);
            else if(v[i][j] == 'G')
                e = pair<int, int>(i, j);
        }
    }
    
    auto a = vector<vector<int>>(n, vector<int>(m));
    array<bitset<4008>, 4008> visited;
    queue<pair<int, int>> q;
    q.emplace(s);
    visited[s.first][s.second] = true;
    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ex = x + dx[i], ey = y + dy[i];
            if(0 <= ex && ex < n && 0 <= ey && ey < m && !visited[ex][ey] && v[ex][ey] != '#')
            {
                a[ex][ey] = a[x][y] + 1;
                visited[ex][ey] = true;
                q.emplace(ex, ey);
            }
        }
    }
    cout << a[e.first][e.second] << endl;
    
    return 0;
}