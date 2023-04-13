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

int n, l, cnt = 0;
int x1, x2;
vector<int> v;
int A[24][24][24];
bitset<24> visited[24][24];

int f(int a, int b, int c)
{
    if(visited[a][b][c])
        return A[a][b][c];
    
    visited[a][b][c] = true;
    if(a > l-1)
        return A[a][b][c] = 0;
    
    int x1 = f(a+1, v[a], c) + abs(b - v[a]);
    int x2 = f(a+1, b, v[a]) + abs(c - v[a]);
    return A[a][b][c] = min(x1, x2);
}

int main()
{
    cin >> n >> x1 >> x2 >> l;
    v.resize(l+1);
    for(int i=0; i<l; i++)
        cin >> v[i];
    cout << f(0, x1, x2) << endl;
    
    return 0;
}