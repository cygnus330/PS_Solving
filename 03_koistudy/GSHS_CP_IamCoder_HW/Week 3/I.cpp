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

//const ll MOD = 1'000'000'007;
const ll MOD = 1000000007;

ll comb(ll n, ll k)
{
    ll A[n+1][k+1];
    for(int i=0; i<=n; i++)
    {
        int t = (int)min((ll)i, k);
        for(int j=0; j<=t; j++)
        {
            if(j == 0 or j == i)
                A[i][j] = 1;
            else
                A[i][j] = (A[i-1][j-1] + A[i-1][j]) % MOD;
        }
    }
    return A[n][k];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int s = 1;
    for(int i=0; i<n; i++)
        s *= 2;
    s--;
    
    if(m < s)
    {
        cout << 0 << endl;
        exit(0);
    }
    
    ll cnt = 0;
    for(int i = s; i <= m; i++)
        cnt += comb(i - 1, i - s);
    cout << cnt << endl;
    
    return 0;
}