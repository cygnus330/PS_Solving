#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,fma,sse2,ssse3,sse4,sse4.1,sse4.2")

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

const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int n, m;
int ax, ay;
array<bitset<1010>, 1010> visited;
array<array<int, 1010>, 1010> A;
queue<pii> q;

int main()
{
	fastio();
	cin >> n >> m >> ax >> ay;
	visited[ax][ay] = true;
	fill(A[0].begin(), A[1009].end(), -1);
	A[ax][ay] = 0;
	q.push({ax, ay});
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int i=0; i<8; i++)
		{
			int ex = x + dx[i], ey = y + dy[i];
			if(ex < 1 || ex > n || ey < 1 || ey > m)
				continue;
			if(visited[ex][ey])
				continue;
			visited[ex][ey] = true;
			A[ex][ey] = A[x][y] + 1;
			q.push({ex, ey});
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	return 0;
}