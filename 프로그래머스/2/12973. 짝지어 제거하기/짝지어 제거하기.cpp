#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> st;
    for (int i = 0, len = s.size(); i < len; ++i)
        if (st.size() && st.top() == s[i]) st.pop();
        else st.push(s[i]);
    return st.empty();
}