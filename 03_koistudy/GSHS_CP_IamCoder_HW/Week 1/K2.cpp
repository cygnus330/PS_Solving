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

int p, ns, t;
vector<int> v[5010];
vector<int> r;

void f(int a)
{
    if(a == 1)
    {
        cout << r.size() << endl;
        for(int i=r.size()-1; i>=0; i--)
            cout << r[i] << endl;
        exit(0);
    }
    else
    {
        for(int i=0; i<v[a].size(); i++)
        {
            r.push_back(v[a][i]);
            f(v[a][i]);
            r.pop_back();
        }
    }
}

int main()
{
    cin >> p >> ns >> t;
    for(int i=0; i<ns; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[b].push_back(a);
        v[c].push_back(a);
    }
    
    r.push_back(t);
    f(t);
    
    return 0;
}