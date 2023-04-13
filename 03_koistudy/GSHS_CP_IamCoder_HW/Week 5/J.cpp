#include <bits/stdc++.h>
//#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

int n, m, t;
vector<int> v;
vector<vector<int>> b;

void sync()
{
    int x = *min_element(v.begin() + 1, v.begin() + n + 1);
    for(int i = 1; i <= n; i++)
        v[i] -= x;
}

signed main()
{
    cin >> n >> m;
    v.resize(n + 1, 0);
    b.resize(n + 1, vector<int>(0, 0));
    for(int i = 0; i < m; i++)
    {
        sync();
        
        int a;
        cin >> a;
        int idx = 1;
        while(v[idx]) idx++;
        v[idx] = a;
        b[idx].emplace_back(i + 1);
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int &j:b[i])
            cout << j << " ";
        cout << endl;
    }
    
    return 0;
}