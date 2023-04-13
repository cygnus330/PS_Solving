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
vector<int> buffer, ed[5010];
int pr[5010];

void f(int a)
{
    if(a == 1)
    {
        buffer.push_back(1);
        return;
    }
    
    buffer.push_back(a);
    f(pr[a]);
}

int main()
{
     cin >> p >> ns >> t;
     for(int i=0; i<ns; i++)
     {
         int a, b, c;
         cin >> a >> b >> c;
         ed[a].push_back(b);
         ed[a].push_back(c);
     }
     
     queue<int> q;
     q.push(1);
     while(!q.empty())
     {
         int x = q.front();
         q.pop();
         
         for(int i=0; i<ed[x].size(); i++)
         {
             pr[ed[x][i]] = x;
             q.push(ed[x][i]);
         }
     }
     
     f(t);
     cout << buffer.size() << endl;
     for(int i=buffer.size()-1; i>=0; i--)
         cout << buffer[i] << endl;
     
     return 0;
}