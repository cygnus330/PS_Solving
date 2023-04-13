#include <iostream>
#include <vector>
#include <string>
using namespace std;

char f(char a)
{
    a -= 'a' - 1;
    a %= 3;
    a += 'a';
    return a;
}

int main()
{
    string a;
    cin >> a;
    vector<char> s;
    for(char &i:a)
    {
        s.push_back(i);
        
        while(s.size() > 1)
        {
            char *p = &s.back();
            if(*p == *(p-1))
            {
                char t = *p;
                s.pop_back(); s.pop_back();
                s.push_back(f(t));
            }
            else
                break;
        }
    }
    
    for(char &i:s)
        cout << i;
    
    return 0;
}