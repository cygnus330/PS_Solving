#include <bits/stdc++.h>
//#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

int n, m, k;
vector<int> ed[51];
int ans, c;
vector<int> t;

void f()
{
	bitset<56> visited;
	for(auto &i:t)
		visited[i] = true;

	queue<int> q;
	visited[1] = true;
	q.emplace(1);

	int cnt = 0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		cnt++;

		for(auto &i:ed[x])
		{
			if(visited[i])
				continue;

			visited[i] = true;
			q.emplace(i);
		}
	}

	if(cnt < ans)
	{
		ans = cnt;
		c = 1;
	}
	else if(cnt == ans)
		c++;
}

void sett(int a, int b)
{
	if(b == 1)
	{
		for(int i = a; i <= n; i++)
		{
			t.push_back(i);
			f();
			t.pop_back();
		}
		return;
	}
	for(int i = a; i <= n; i++)
	{
		t.push_back(i);
		sett(i + 1, b - 1);
		t.pop_back();
	}
}

signed main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		ed[s].emplace_back(e);
		//ed[e].emplace_back(s);
	}

	ans = INT_MAX;
	sett(2, k);

	cout << ans << " " << c << endl;

	return 0;
}