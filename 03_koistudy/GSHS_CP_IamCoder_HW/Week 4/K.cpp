#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> s;
    pair<int, int> t = pair<int, int>(0, -1);
    for(int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        
        while(!s.empty() && s.back() <= a)
            s.pop_back();
        
        int sz = s.size();
        if(t.first < sz)
            t = pair<int, int>(sz, i + 1);
        s.push_back(a);
    }
    printf("%d %d\n", t.second, t.first);
    
    return 0;
}