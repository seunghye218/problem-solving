#include <string>
#include <stack>
using namespace std;

inline bool is_valid_brace(stack<char> &st, const char &c);

int solution(string s) {
    stack<char> st;
    int i, j, end, len = s.size(), answer = 0;

    for (i = 0; i < len; ++i) {
        for (j = i, end = i + len; j < end; ++j) {
            if (!is_valid_brace(st, s[j % len]))
                break;
        }
        if (!st.size() && j == end)
            ++answer;
        st = stack<char>();
    }
    return answer;
}

// switch 문으로 속도 향상
inline bool is_valid_brace(stack<char> &st, const char &c) {
    switch (c) {
                case '(':
                    st.push('('); break;
                case ')': 
                    if (st.empty() || st.top() != '(')
                        return false; 
                    else  st.pop(); break;
                case '[': 
                    st.push('['); break;
                case ']':
                    if (st.empty() || st.top() != '[')
                        return false;
                    else st.pop(); break;
                case '{': 
                    st.push('{'); break;
                case '}': 
                    if (st.empty() || st.top() != '{')
                        return false;
                    else st.pop(); break;
                default:
                    return false;;
            }
    return true;
}