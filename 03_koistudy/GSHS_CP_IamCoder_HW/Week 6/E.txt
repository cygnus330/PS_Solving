#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;

int n;
int A[20][4][4];

signed main()
{
	cin >> n;
	A[1][1][1] = 1;
	A[2][1][2] = 1; A[2][2][1] = 1;
	A[3][1][1] = 1; A[3][2][1] = 1; A[3][3][1] = 1;
	for(int i = 4; i <= n; i++)
	{
		A[i][1][1] = A[i-1][2][1] + A[i-1][2][2] + A[i-1][3][1] + A[i-1][3][2];
		A[i][1][2] = A[i-1][1][1];
		A[i][2][1] = A[i-2][1][1] + A[i-2][1][2] + A[i-2][3][1] + A[i-2][3][2];
		A[i][2][2] = A[i-2][2][1];
		A[i][3][1] = A[i-3][1][1] + A[i-3][1][2] + A[i-3][2][1] + A[i-3][2][2];
		A[i][3][2] = A[i-3][3][1];
	}

	int cnt = 0;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j < 3; j++)
			cnt += A[n][i][j];
	cout << cnt << endl;

	return 0;
}