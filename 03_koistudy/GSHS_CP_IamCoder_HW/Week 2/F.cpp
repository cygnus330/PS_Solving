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

ll ncr(int a, int b)
{
    ll cnt = 1;
    for(int i=1; i<=b; i++)
    {
        cnt *= a-i+1;
        cnt /= i;
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << ncr(n, k) << endl;
    
    return 0;
}