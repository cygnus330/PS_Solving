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

void f(int a, int b, vector<int> &v, int &cnt, int &n)
{
    if(a <= -1)
    {
        if(b || (v[0] && v[1]))
            return;
        
        cnt++;
        /*
        for(int &i:v)
            cerr << i << " ";
        cerr << endl;*/
        return;
    }
    
    if(a == n-1)
    {
        v[a] = 1;
        f(a-2, b-1, v, cnt, n);
        v[a] = 0;
        
        f(a-1, b, v, cnt, n);
        
        return;
    }
    
    if(v[a+1])
    {
        v[a] = 1;
        f(a-2, b-1, v, cnt, n);
        v[a] = 0;
        f(a-1, b, v, cnt, n);
        
        return;
    }
    
    v[a] = 1;
    f(a-1, b-1, v, cnt, n);
    v[a] = 0;
    f(a-1, b, v, cnt, n);
}

int main()
{
    int n, k, cnt = 0;
    vector<int> v;
    cin >> n >> k;
    if(n == 1)
    {
        cout << 1 << endl;
        exit(0);
    }
    
    v.assign(n, 0);
    f(n-1, k, v, cnt, n);
    cout << cnt << endl;
    
    return 0;
}