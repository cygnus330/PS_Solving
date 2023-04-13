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

int n, q;
int A[501][501];

int main()
{
    fastio();
    cin >> n >> q;
    for(int T=0; T<q; T++)
    {
        int a, b, c, d, w;
        cin >> a >> b >> c >> d >> w;
        for(int i=a-1; i<c; i++)
        {
            A[i][b-1] += w;
            A[i][d] -= w;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        for(int j=0; j<n; j++)
        {
            cnt += A[i][j];
            cout << cnt << " ";
        }
        cout << endl;
    }
    
    return 0;
}