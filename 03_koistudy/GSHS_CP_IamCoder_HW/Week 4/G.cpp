#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    vector<string> b;
    string a;
    cin >> a;
    vector<char> s;
    int idx = '1';
    for(char &i:a)
    {
        b.push_back("push");
        s.push_back(i);
        while(s.back() == idx && !s.empty())
        {
            b.push_back("pop");
            s.pop_back();
            idx++;
        }
    }
    while(!s.empty())
    {
        if(s.back() == idx)
        {
            b.push_back("pop");
            s.pop_back();
            idx++;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for(string &i:b)
        cout << i << endl;
    
    return 0;
}