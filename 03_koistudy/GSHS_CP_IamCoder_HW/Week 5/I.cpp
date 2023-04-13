#include <bits/stdc++.h>
//#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m+1, vector<int>(0, 0));
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[a].push_back(i + 1);
    }
    
    for(int i = 1; i <= m; i++)
    {
        cout << v[i].size();
        for(int &j:v[i])
            cout << " " << j;
        cout << endl;
    }
    
    return 0;
}