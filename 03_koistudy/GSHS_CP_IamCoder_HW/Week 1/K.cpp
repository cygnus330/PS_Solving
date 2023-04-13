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

int main()
{
    string a;
    vector<int> e, m;
    array<int, 2020> v = {};
    ll ans = 0; int n;
    
    fastio();
    cin >> a;
    n = a.length();
    e.assign(n, 0);
    m.assign(n, 0);
    reverse(all(a));
    
    e[0] = 1;
    for(int i=1; i<n; i++)
    {
        e[i] = e[i-1] * 10;
        e[i] %= 2019;
    }
    
    m[0] = a[0] - '0';
    v[m[0]]++;
    for(int i=1; i<n; i++)
    {
        m[i] = m[i-1] + (int)(a[i] - '0') * e[i];
        m[i] %= 2019;
        
        if(m[i])
        {
            ans += v[m[i]];
            v[m[i]]++;
        }
        else
        {
            v[0]++;
            ans += v[0];
        }
        
        if(a[i] == '0' && m[i] == m[i-1])
            ans--;
    }
    cout << ans << endl;
    
    return 0;
}