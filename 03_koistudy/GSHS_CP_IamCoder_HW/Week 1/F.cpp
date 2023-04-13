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

const array<int, 12> M = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
const array<string, 7> v = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
int a, b, c, Y;

ll lcm(int a, int b)
{
    return a*b/__gcd(a, b);
}

void f(int &a, int &b, int c)
{
    while(c > M[a])
    {
        c -= M[a];
        a++;
    }
    b = c;
}

int main()
{
    cin >> a >> b >> c;
    int d = lcm(lcm(a, b), c) + 1;
    int e = d%7 + 6;
    e %= 7;
    for(auto &i:M)
        Y += i;
    
    int Ye, Mo = 0, Da = 0;
    Ye = 2100 + d/Y;
    d %= Y;
    f(Mo, Da, d);
    printf("%04d-%02d-%02d ", Ye, Mo, Da);
    cout << v[e] << endl;
    
    return 0;
}
