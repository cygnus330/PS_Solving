#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<char> s;
    string b;
    cin >> b;
    
    for(char &a:b)
    {
        if(a == '(' || a == '[' || a == '{')
            s.push_back(a);
        else
        {
            if(s.empty())
            {
                printf("X");
                return 0;
            }
            else if(a == ')')
            {
                if(s.back() == '(')
                    s.pop_back();
                else
                {
                    printf("X");
                return 0;
                }
            }
            else if(a == ']')
            {
                if(s.back() == '[')
                    s.pop_back();
                else
                {
                    printf("X");
                return 0;
                }
            }
            else if(a == '}')
            {
                if(s.back() == '{')
                    s.pop_back();
                else
                {
                    printf("X");
                return 0;
                }
            }
            else
            {
                printf("X");
                return 0;
            }
        }
    }
    
    if(s.empty())
        printf("O");
    else
        printf("X");
    
    return 0;
}