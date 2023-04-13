#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int n, m, k;

signed main()
{
	cin >> n >> m >> k;
	vector<vector<int>> v;

	v.push_back(vector<int>{n, m});
	int cnt = 2;
	while(cnt < k)
	{
		int sz = v.size();
		v.push_back(vector<int>(0));
		auto &i = v[sz - 1];
		int s = i.size();
		for(int a = 0; a < s; a++)
		{
			v[sz].push_back((i[a] * n) % MOD);
			v[sz].push_back((i[a] * m) % MOD);
		}
		cnt += v[sz].size();
	}

	int idx = 0;
	for(auto &i:v)
	{
		for(auto &j:i)
		{
			idx++;
			//cout << j << " ";
			if(idx == k)
			{
				cout << j;
				return 0;
			}
		}
		//cout << endl;
	}

	return 0;
}