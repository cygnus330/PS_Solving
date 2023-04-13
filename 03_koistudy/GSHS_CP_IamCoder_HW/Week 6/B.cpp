#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

int n;
string a;

void f(int x)
{
	if(x >= n)
		return;

	f(2*x + 1);
	cout << a[x] << " ";
	f(2*x + 2);
}

signed main()
{
	cin >> n >> a;
	f(0);

	return 0;
}