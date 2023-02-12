#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
void sync() // scanf() printf() X , only single-core
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int v, e, k;
int A[20010];
vector<pii> node[20010];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    sync();
    cin >> v >> e >> k;
    for(int i=1; i<=v; i++)
        A[i] = 1e9;
    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({v, w});
    }
    A[k] = 0;
    pq.push({0, k});

    while(!pq.empty())
    {
        int v = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        for(int i=0; i<node[v].size(); i++)
        {
            int dv = node[v][i].first, dw = node[v][i].second;

            if(w + dw < A[dv])
            {
                A[dv] = w + dw;
                pq.push({w + dw, dv});
            }
        }
    }

    for(int i=1; i<=v; i++)
        if(A[i] >= 1e9)
            cout << "INF\n";
    else
        cout << A[i] << endl;

    return 0;
}
