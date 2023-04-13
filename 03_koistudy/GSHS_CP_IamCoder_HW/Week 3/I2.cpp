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

const int MOD = 1000000007;

int main()
{
    int A[730][1010]; // 730 1010
    int p[6]; // 6

    int n, m;
    cin >> n >> m;
    
    p[0] = 1;
    for(int i = 1; i < 6; i++)
        p[i] = p[i-1] * 3;
    
    memset(A, 0, sizeof(A));
    A[0][0] = 1;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < p[n] - 1; j++)
        {
            vector<int> v[3];
            int t = j;
            for(int k = 0; k < n; k++)
            {
                v[t % 3].push_back(k);
                t /= 3;
            }
           
            for(int k = 0; k < 3; k++)
            {
                if(v[k].empty())
                    continue;
                
                t = v[k].front();
                for(int l = 0; l < 3; l++)
                {
                    if(k == l)
                        continue;
                    
                    if(!v[l].empty())
                        if(v[l].front() < t)
                            continue;
                    
                    int e = j + p[t] * (l - k);
                    A[e][i+1] += A[j][i];
                    A[e][i+1] %= MOD;
                }
            }
        }
    
    int ans = 0;
    for(int i = 0; i <= m; i++)
    {
        ans += A[p[n] - 1][i];
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}