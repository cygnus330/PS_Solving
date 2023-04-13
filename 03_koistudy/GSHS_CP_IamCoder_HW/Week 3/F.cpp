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
ll ans;
vector<string> buffer = {"1 : A->C",
"1 : C->B",
"2 : A->C",
"1 : B->C",
"1 : C->A",
"2 : C->B",
"1 : A->C",
"1 : C->B",
"3 : A->C",
"1 : B->C",
"1 : C->A",
"2 : B->C",
"1 : A->C",
"1 : C->B",
"2 : C->A",
"1 : B->C",
"1 : C->A",
"3 : C->B",
"1 : A->C",
"1 : C->B",
"2 : A->C",
"1 : B->C",
"1 : C->A",
"2 : C->B",
"1 : A->C",
"1 : C->B",
"4 : A->C",
"1 : B->C",
"1 : C->A",
"2 : B->C",
"1 : A->C",
"1 : C->B",
"2 : C->A",
"1 : B->C",
"1 : C->A",
"3 : B->C",
"1 : A->C",
"1 : C->B",
"2 : A->C",
"1 : B->C",
"1 : C->A",
"2 : C->B",
"1 : A->C",
"1 : C->B",
"3 : C->A",
"1 : B->C",
"1 : C->A",
"2 : B->C",
"1 : A->C",
"1 : C->B",
"2 : C->A",
"1 : B->C",
"1 : C->A",
"4 : C->B",
"1 : A->C",
"1 : C->B",
"2 : A->C",
"1 : B->C",
"1 : C->A",
"2 : C->B",
"1 : A->C",
"1 : C->B",
"3 : A->C",
"1 : B->C",
"1 : C->A",
"2 : B->C",
"1 : A->C",
"1 : C->B",
"2 : C->A",
"1 : B->C",
"1 : C->A",
"3 : C->B",
"1 : A->C",
"1 : C->B",
"2 : A->C",
"1 : B->C",
"1 : C->A",
"2 : C->B",
"1 : A->C",
"1 : C->B",
"5 : A->C",
"1 : B->C",
"1 : C->A",
"2 : B->C",
"1 : A->C",
"1 : C->B",
"2 : C->A",
"1 : B->C",
"1 : C->A",
"3 : B->C",
"1 : A->C",
"1 : C->B",
"2 : A->C",
"1 : B->C",
"1 : C->A",
"2 : C->B",
"1 : A->C",
"1 : C->B",
"3 : C->A",
"1 : B->C"};

ll Pow(ll n, ll k, ll m)
{
    if(k == 0)
        return 1;
    if(k%2 == 0)
    {
        ll t = Pow(n, k/2, m);
        return (t*t) % m;
    }
    ll t = Pow(n, k/2, m);
    t = (t*t) % m;
    return (n*t) % m;
}

/*void f(int a, char s, char e, char m)
{
    if(buffer.size() >= 100)
    {
        for(int i=0; i<100; i++)
            cout << buffer[i].first << " : " << buffer[i].second.first << "->" << buffer[i].second.second << endl;
        cout << ans << endl;
        exit(0);
    }
    
    if(a == 1)
    {
        buffer.push_back({1, {s, m}});
        buffer.push_back({1, {m, e}});
        return;
    }
    
    f(a-1, s, e, m);
    buffer.push_back({a, {s, m}});
    f(a-1, e, s, m);
    buffer.push_back({a, {m, e}});
    f(a-1, s, e, m);
}*/

int main()
{
    ll n;
    cin >> n;
    ans = ((MOD - 1) + Pow(3, n, MOD)) % MOD;
    if(n >= 5)
    {
        for(int i=0; i<100; i++)
            cout << buffer[i] << endl;
    }
    else
    {
        for(int i=0; i<ans; i++)
            cout << buffer[i] << endl;
    }
    cout << ans << endl;
    
    return 0;
}