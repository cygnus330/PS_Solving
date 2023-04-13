#include <bits/stdc++.h>
using namespace std;

const int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    
    auto v = vector<vector<int>>(n, vector<int>(m, -1));
    //array<bitset<1008>, 1008> visited;
    
    int sx, sy;
    cin >> sx >> sy;
    sx--, sy--;
    queue<pair<int, int>> q;
    v[sx][sy] = 0;
    q.emplace(sx, sy);
    
    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second; q.pop();
        for(int i = 0; i < 8; i++)
        {
            int ex = x + dx[i], ey = y + dy[i];
            if(0 <= ex && ex < n && 0 <= ey && ey < m && v[ex][ey] == -1)
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