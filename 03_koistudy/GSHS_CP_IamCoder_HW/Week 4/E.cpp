#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

string a;

ll f(int s, int e)
{
    while(a[s] == '(' && a[e] == ')' && s < e)
    {
        s++;
        e--;
    }
    
    vector<int> v[4];
    int cnt = 0;
    for(int i = s; i <= e; i++)
    {
        char x = a[i];
        if(x == '(')
            cnt++;
        else if(x == ')')
            cnt--;
        else if(cnt == 0)
        {
            if(x == '+')
                v[0].push_back(i);
            else if(x == '-')
                v[1].push_back(i);
            else if(x == '*')
                v[2].push_back(i);
            else if(x == '/')
                v[3].push_back(i);
        }
    }
    
    if(!v[0].empty())
    {
        int t = v[0].front();
        ll x = f(s, t - 1) + f(t + 1, e);
        //cerr << s << " " << e << " " << x << endl;
        return x;
    }
    if(!v[1].empty())
    {
        int t = v[1].front();
        ll x = f(s, t - 1) - f(t + 1, e);
        //cerr << s << " " << e << " " << x << endl;
        return x;
    }
    
    if(v[2].size() + v[3].size() == 0)
    {
        //cerr << s << " " << e << " " << stoll(a.substr(s, e - s + 1)) << endl;
        return stoll(a.substr(s, e - s + 1));
    }
    
    vector<pii> T;
    T.push_back({s-1, 1});
    T.push_back({e+1, 0});
    for(int &i:v[2])
        T.push_back({i, 1});
    for(int &i:v[3])
        T.push_back({i, 2});
    sort(T.begin(), T.end());
    int sz = T.size();
    ll calc = 1;
    for(int i = 0; i < sz - 1; i++)
    {
        int es = T[i].first + 1, ee = T[i + 1].first - 1;
        ll x = f(es, ee);
        //cerr << es << " " << ee << " " << x << " t\n";
        if(T[i].second == 1)
            calc *= x;
        else
            calc /= x;
    }
    return calc;
}

int main()
{
    cin >> a;
    cout << f(0, a.size() - 1) << endl;
    
    return 0;
}