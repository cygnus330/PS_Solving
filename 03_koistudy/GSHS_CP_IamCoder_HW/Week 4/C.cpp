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
    string a;
    cin >> a;
    int sz = a.size();
    
    vector<char> s;
    for(char &i:a)
    {
        if(i == '+' || i == '-')
        {
            while(!s.empty())
            {
                cout << s.back();
                s.pop_back();
            }
            s.push_back(i);
        }
        else if(i == '*' || i == '/')
        {
            while(!s.empty())
            {
                if(s.back() == '+' || s.back() == '-')
                    break;
                
                cout << s.back();
                s.pop_back();
            }
            s.push_back(i);
        }
        else
            cout << i;
    }
    
    while(!s.empty())
    {
        cout << s.back();
        s.pop_back();
    }
    
    return 0;
}