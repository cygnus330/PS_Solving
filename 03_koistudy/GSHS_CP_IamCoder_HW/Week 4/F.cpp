#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n, cnt = 1;
    cin >> n;
    vector<int> v(n);
    vector<char> buffer;
    queue<int> q;
    stack<int> s;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    
    while(!q.empty())
    {
        if(s.empty())
        {
            if(cnt > n)
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                s.push(cnt);
                cnt++;
                buffer.push_back('+');
            }
        }
        else
        {
            if(s.top() == q.front() && !s.empty())
            {
                s.pop();
                q.pop();
                buffer.push_back('-');
            }
            else if(cnt > n)
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                s.push(cnt);
                cnt++;
                buffer.push_back('+');
            }
        }
    }
    
    if(s.empty())
    {
        for(int i=0; i<buffer.size(); i++)
            cout << buffer[i] << endl;
    }
    else
        cout << "NO" << endl;
    
    return 0;
}