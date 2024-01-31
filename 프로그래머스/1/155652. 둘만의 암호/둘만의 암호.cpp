#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string alpha(26, 'a');
    for (int i = 1; i < 26; ++i)
        alpha[i] += i;
    for (char &c : skip)
        alpha.erase(alpha.begin() + alpha.find(c));
    for (char &c : s)
        c = alpha[(alpha.find(c) + index) % alpha.size()];
    return s;
}