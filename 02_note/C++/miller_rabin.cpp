#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void fastio() // cannot use scanf(), printf() and only 1T
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll power(ll a, ll b, ll p)
{
    a %= p;
    ll cnt = 1;
    while(b)
    {
        if(b & 0b1)
            cnt = (cnt * a) % p;
        b >>= 1;
        a = (a*a) % p;
    }
    
    return cnt;
}

bool miller_rabin(ll a, ll b)
{
    if(b%a == 0)
        return 1;
    
    unsigned long long cnt = a-1;
    while(true)
    {
        unsigned long long cnt2 = power(b, cnt, a);
        if(cnt2 == a-1)
            return 1;
        else if(cnt & 0b1)
            return cnt2 == 1 or cnt2 == a-1;
        cnt >>= 1;
    }
}

int main()
{
    int cnt = 0;
    ll ptr = 100000000000000000 + 1;
    while(cnt < 5)
    {
        ptr -= 2;
        if(!miller_rabin(ptr, 2) and !miller_rabin(ptr, 7) and !miller_rabin(ptr, 61))
            continue;
        cout << ptr << endl;
        cnt++;
    }//check ptr is prime
}