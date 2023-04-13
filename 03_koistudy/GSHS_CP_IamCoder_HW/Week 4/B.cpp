#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

string a;

int f(int s, int e)
{
    int ans = 0;
    vector<pair<char, int>> v;
    for(int i = s; i <= e; i++)
    {
        char t = a[i];
        if(t == '(' || t == '[')
            v.push_back(pair<char, int>(t, i));
        else
        {
            if(v.size() == 1)
            {
                int c;
                if(t == ')')
                    c = 2;
                else
                    c = 3;
                
                if(v.back().second == i - 1)
                    ans += c;
                else
                    ans += c * f(v.begin()->second + 1, i - 1);
            }
            v.pop_back();
        }
    }
    
    return ans;
}

int main()
{
    vector<char> v;
    cin >> a;
    int sz = a.size();
    for(int i = 0; i < sz; i++)
    {
        char t = a[i];
        if(t == '(' || t == '[')
            v.push_back(t);
        else
        {
            if(v.empty())
            {
                cout << 0;
                return 0;
            }
            else if(t == ')')
            {
                if(v.back() != '(')
                {
                    cout << 0;
                    return 0;
                }
            }
            else
            {
                if(v.back() != '[')
                {
                    cout << 0;
                    return 0;
                }
            }
            v.pop_back();
        }
    }
    cout << f(0, sz - 1);
    
    return 0;
}