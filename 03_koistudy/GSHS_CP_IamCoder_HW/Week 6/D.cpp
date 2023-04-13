#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

signed main()
{
	int p, ns, t;
	int dist[5010], back[5010];
	bitset<5010> visited;
	vector<int> ed[5010];

	cin >> p >> ns >> t;
	for(int i = 0; i < ns; i++)
	{
		int s, e1, e2;
		cin >> s >> e1 >> e2;
		ed[s].push_back(e1);
		ed[s].push_back(e2);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;
	dist[1] = 1;
	back[1] = 0;

	while(!q.empty())
	{
		auto x = q.front();
		q.pop();

		for(auto &i:ed[x])
		{
			if(visited[i])
				continue;

			q.push(i);
			visited[i] = true;
			dist[i] = dist[x] + 1;
			back[i] = x;
		}
	}
	cout << dist[t] << endl;

	vector<int> v = {t};
	while(back[v.back()] != 0)
		v.push_back(back[v.back()]);
	reverse(all(v));
	for(auto &i:v)
		cout << i << endl;

	return 0;
}