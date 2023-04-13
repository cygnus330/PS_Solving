#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};

queue<pii> q;
map<pii, int> db;
int n, m, k;
int sx, sy;

bool f(int x, int y)
{
	int cnt = 0;
	for(int i = 0; i < 8; i++)
	{
		int ex = x + dx[i], ey = y + dy[i];
		if(0 <= ex && ex < n && 0 <= ey && ey < m)
			cnt++;
	}
	
	if(cnt > 0) return true;
	return false;
}

signed main()
{
	cin >> n >> m >> sx >> sy >> k;
	db.insert(make_pair(pii(sx - 1, sy - 1), 1));
	q.push(pii(sx - 1, sy - 1));
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		int t = db[{x, y}];
		q.pop();

		if(t == k + 1)
			continue;

		for(int i = 0; i < 8; i++)
		{
			int ex = x + dx[i], ey = y + dy[i];
			if(0 <= ex && ex < n && 0 <= ey && ey < m && (db.find({ex, ey}) == db.end()))
			{
				db.insert({{ex, ey}, t + 1});
				q.push({ex, ey});
			}
		}
	}

	int cnt = 0;
	for(auto i = db.begin(); i != db.end(); i++)
		if(i->second % 2 != k % 2 && i->second > 0 && f(i->first.first, i->first.second))
			cnt++;
	cout << n * m - cnt << endl;

	return 0;
}