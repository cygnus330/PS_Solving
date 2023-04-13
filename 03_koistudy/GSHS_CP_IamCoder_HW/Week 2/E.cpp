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

const ll MOD = 2052506102;

int n;
array<array<ll, 16>, 16> A;
array<bitset<16>, 16> visited;

ll f(int a, int b)
{
    if(a < 0 || b < 0)
        return 0;
    
    if(visited[a][b])
        return A[a][b];
    visited[a][b] = true;
    
    ll cnt = 0;
    if(a == b)
    {
        cnt = 2*f(a-1, b-1);
        for(int i=1; i<=3; i++)
            cnt += f(a-i, b) + f(a, b-i);
        cnt /= 2;
    }
    else if(a > b)
    {
        for(int i=1; i<=3; i++)
            cnt += f(a-i, b);
    }
    else
    {
        for(int i=1; i<=3; i++)
            cnt += f(a, b-i);
    }
    
    return A[a][b] = cnt % MOD;
}

int main()
{
    cin >> n;
    A.fill({});
    visited[0][0] = 1;
    A[0][0] = 1;
    cout << f(n, n) << endl;
    
    return 0;
}