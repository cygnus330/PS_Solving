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

void f(vector<int> &v, int n, int k)
{
    if(n == 0)
    {
        for(auto &i:v)
        {
            for(int j=0; j<i; j++)
                cout << '*';
            cout << endl;
        }
        cout << endl;
        return;
    }
    for(int i=min(n, k); i>=1; i--)
    {
        v.push_back(i);
        f(v, n-i, i);
        v.pop_back();
    }
}


int main()
{
    int n;
    vector<int> v;
    cin >> n;
    f(v, n, n);
    
    return 0;
}