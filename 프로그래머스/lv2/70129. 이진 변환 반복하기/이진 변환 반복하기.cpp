#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int cnt_zero(const string &s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            ++cnt;
        }
    }
    return cnt;
}

string  bin_trans(int cnt_one) {
    string s;
    while (cnt_one) {
        s += cnt_one % 2 ? '1' : '0';
        cnt_one >>= 1;
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int i = 0, zeros = 0;

    while (s.size() > 1) {
        zeros = cnt_zero(s);
        answer[1] += zeros;
        s = bin_trans(s.size() - zeros);
        ++i;
    }
    answer[0] = i;
    return answer;
}