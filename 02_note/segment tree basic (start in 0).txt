#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void sync() // scanf() printf() X , only single-core
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//segment tree (basic) - BOJ 2042 example
//vector<ll> tree, arr; // tree: 2n-1, arr:n push need
ll arr[2000001], tree[3000002]; // tree: 2n-1, arr:n (array size need)
int n, m, k;

//init(1, 0, n-1);
void init(int node, int first, int last) //refresh all tree
{
    if(first == last)
    {
        tree[node] = arr[first];
        return;
    }
    init(node*2, first, (first+last)/2);
    init(node*2 + 1, (first+last)/2+1, last);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

//sum(1, 0, n-1, b-1, c-1); - calc sum b to c
ll sum(int node, int first, int last, int left, int right) //calculate sum left to right
{
    if(left > last || right < first)
        return 0;
    if(left <= first && right >= last)
        return tree[node];
    return sum(node*2, first, (first+last)/2, left, right) + sum(node*2+1, (first+last)/2+1, last, left, right);
}

//update(1, 0, n-1, b-1, c); - update arr[b] = c and segtree
void update(int node, int first, int last, int index, ll change) //update arr[index] to change
{
    if(index < first || index > last)
        return;

    if(first == last)
    {
        arr[index] = change;
        tree[node] = change;
        return;
    }
    update(node*2, first, (first+last)/2, index, change);
    update(node*2+1, (first+last)/2+1, last, index, change);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

int main()
{
    sync();

    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    init(1, 0, n-1);
    for(int i=0; i<(m+k); i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1)
            update(1, 0, n-1, b-1, c);
        else
            cout << sum(1, 0, n-1, b-1, c-1) << endl;
    }

    return 0;
}
