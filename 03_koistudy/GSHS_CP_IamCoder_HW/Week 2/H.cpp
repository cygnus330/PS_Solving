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

int main()
{
    int n, cnt = 0;
    vector<int> s;
    cin >> n;
    if(n == 1)
    {
        int a;
        cin >> a;
        cout << a << endl;
        return 0;
    }
    
    s.resize(n);
    for(int i=0; i<n; i++)
        cin >> s[i];
    
    sort(all(s));
    while(s.size() > 3)
    {
        cnt += min(*s.begin() + *(s.end()-2), 2**(s.begin()+1)) + *s.begin() + *(s.end()-1);
        s.pop_back(); s.pop_back();
    }
    
    if(s.size() == 3)
    {
        for(int i=0; i<3; i++)
            cnt += s[i];
    }
    else if(s.size() == 2)
        cnt += max(s[0], s[1]);
    else
        cnt += s[0];
    cout << cnt << endl;
    
    return 0;
}