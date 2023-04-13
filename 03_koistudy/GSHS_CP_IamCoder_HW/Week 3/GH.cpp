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

const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    ll A = 2, B = 2, D = 1;
    for(int i=2; i<=n; i++)
    {
        ll nA, nB, nD;
        nA = D + 2*B + 2;
        nB = 2*B + 2;
        nD = A + 1 + B;
        nA %= MOD, nB %= MOD, nD %= MOD;
        A = nA, B = nB, D = nD;
    }
    cout << A << endl;
    
    return 0;
}
