#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma,sse2,sse3")

#include <bits/stdc++.h>
#include <immintrin.h>
#define all(v) (v).begin(), (v).end()
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
void sync() // scanf() printf() X , only single-core
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
bool A[40][40];

//simulated-annealing : 예제는 BOJ 2582
#include <random>
mt19937_64 seed(rand());
uniform_real_distribution<double> rng(0, 1);
uniform_int_distribution<int> rng_int(0, 1000000);
double k = 10, d = 0.9995, t = 1;
double lim; //온도 t가 임계온도 lim 이상일때까지 while 때려박는 방법도 있음
int ans = INT_MAX;

int score_cnt()
{
    int s = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            s += A[i][j];
    return s;
}

void turn(int a, bool b)
{
    if(b)
    {
        for(int i=0; i<n; i++)
            A[i][a] = 1 - A[i][a];
    }
    else
    {
        for(int i=0; i<n; i++)
            A[a][i] = 1 - A[a][i];
    }
}

void opti()
{
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        for(int j=0; j<n; j++)
            cnt += A[j][i];
        if(cnt * 2 > n)
            turn(i, 1);
    }
}

void sim_an()
{
    double E1, E2;
    bool B[40][40];
    for(int i=0; i<300000; i++)
    {
        //초기 상태 에너지
        E1 = score_cnt();

        //인접 상태로 전이
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                B[i][j] = A[i][j];
        turn(rng_int(seed)%n, 0);
        opti();

        //전이 상태 에너지
        E2 = score_cnt();

        //전이 확률 계산
        double p = exp((E1-E2)/(k*t));
        if(p < rng(seed))
        {
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    A[i][j] = B[i][j];
        }

        //답 새로고침, 온도 내림
        t *= d;
        ans = min(ans, score_cnt());
    }
}

int main()
{
    sync();
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string a;
        cin >> a;
        for(int j=0; j<n; j++)
        {
            if(a[j] == 'H')
                A[i][j] = 0;
            else
                A[i][j] = 1;
        }
    }

    sim_an();
    cout << ans << endl;

    return 0;
}
