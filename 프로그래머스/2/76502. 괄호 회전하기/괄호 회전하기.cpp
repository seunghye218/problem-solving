#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
    stack<char> vs;
    int len = s.size(), answer = 0;
    bool    invalid = false;
    for (int i = 0; i < len; ++i) {
        for (int j = i, end = i + len; j < end; ++j) {
            switch (s[j % len]) {
                case '(':
                    vs.push('('); break;
                case ')': 
                    if (vs.empty() || vs.top() != '(') invalid = true; 
                    else  vs.pop();
                    break;
                case '[': 
                    vs.push('[');break;
                case ']':
                    if (vs.empty() || vs.top() != '[') invalid = true; 
                    else vs.pop();
                    break;
                case '{': 
                    vs.push('{'); break;
                case '}': 
                    if (vs.empty() || vs.top() != '{') invalid = true;
                    else vs.pop();
                    break;
                default:
                    invalid = true;
            }
            if (invalid)
                break;
        }
        if (invalid || vs.size())
            invalid = false;
        else
            ++answer;
        vs = stack<char>();
    }
    return answer;
}
