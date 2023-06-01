#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<int> ed[2004];
bitset<2004> visited;

signed main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		ed[s].emplace_back(e);
		ed[e].emplace_back(s);
	}

/*
	for(int i = 1; i <= n; i++)
		sort(all(ed[i]), [](int a, int b){return a < b;});
*/

	queue<int> q;
	visited[1] = true;
	q.push(1);

	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		cout << x << " ";
		for(auto &i:ed[x])
		{
			if(visited[i])
				continue;

			visited[i] = true;
			q.push(i);
		}
	}

	return 0;
}