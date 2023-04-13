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

int n, m;
array<ll, 100010> A;
array<ll, 100010 * 3> L, lazy;

ll init(int n, int s, int e)
{
    if(s == e)
        return L[n] = A[s];
    
    return L[n] = init(2*n, s, (s+e)/2) + init(2*n + 1, (s+e)/2 + 1, e);
}

void update_l(int n, int s, int e)
{
    if(lazy[n] == 0)
        return;
    
    L[n] = (e - s + 1) * lazy[n];
    if(s != e)
    {
        lazy[2*n] = lazy[n];
        lazy[2*n + 1] = lazy[n];
    }
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, ll v)
{
    update_l(n, s, e);
    if(r < s || l > e)
        return;
    
    if(l <= s && e <= r)
    {
        L[n] = (e - s + 1) * v;
        if(s != e)
        {
            lazy[2*n] = v;
            lazy[2*n + 1] = v;
        }
        return;
    }
    
    update(2*n, s, (s+e)/2, l, r, v);
    update(2*n+1, (s+e)/2 + 1, e, l, r, v);
    L[n] = L[2*n] + L[2*n+1];
}

ll query(int n, int s, int e, int l, int r)
{
    update_l(n, s, e);
    if(r < s || l > e)
        return 0;
    if(l <= s && e <= r)
        return L[n];
    
    ll cnt = query(2*n, s, (s+e)/2, l, r);
    return cnt + query(2*n+1, (s+e)/2 + 1, e, l, r);
}

int main()
{
    fastio();
    cin >> n >> m;
    //init(1, 0, n-1);
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        update(1, 0, n-1, a-1, b-1, c);
    }
    
    for(int i=0; i<n; i++)
    {
        cout << query(1, 0, n-1, i, i) << " ";
    }
}