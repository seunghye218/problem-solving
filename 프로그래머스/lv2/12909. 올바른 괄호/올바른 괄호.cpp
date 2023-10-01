#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (*it == '(')
            st.push('q');
        else {
            if (!st.size())
                return false;
            st.pop();
        }
    }
    if (st.size())
        return false;
    return true;
}