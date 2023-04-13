#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int n;
bitset<40> A[40];
vector<int> b;

int f(int sx, int sy)
{
	queue<pii> q;
	q.emplace(sx, sy);
	A[sx][sy] = false;

	int cnt = 0;
	while(!q.empty())
	{
		//auto [x, y] = q.front();
		int x = q.front().first, y = q.front().second;
		q.pop();

		cnt++;
		for(int i = 0; i < 4; i++)
		{
			int ex = x + dx[i], ey = y + dy[i];
			if(0 <= min(ex, ey) && max(ex, ey) < n)
			{
				if(!A[ex][ey])
					continue;

				A[ex][ey] = false;
				q.emplace(ex, ey);
			}
		}
	}

	return cnt;
}

signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		for(int j = 0; j < n; j++)
			A[i][j] = a[j] - '0';
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(A[i][j])
				b.push_back(f(i, j));
	sort(all(b));
	cout << b.size() << endl;
	for(auto &i:b)
		cout << i << endl;

	return 0;
}