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

int n;
vector<int> v;
array<int, 80010> h;

int main()
{
    fastio();
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> h[i];
    
    int last = 0;
    for(int i=0; i<n; i++)
        if(h[last] < h[i])
        {
            v.push_back(i - last);
            last = i;
        }
    v.push_back(n - last);
    
    ll cnt = 0;
    for(auto &i:v)
        cnt += (i*(i+1))/2;
    cout << cnt << endl;
    
    return 0;
}