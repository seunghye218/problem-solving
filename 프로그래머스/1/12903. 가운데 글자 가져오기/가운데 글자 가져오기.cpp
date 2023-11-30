#include <string>
using namespace std;

string solution(string s) {
    int half_len = (s.size() - 1) / 2;
    if (s.size() & 1)
        return s.substr(half_len, 1);
    else
        return s.substr(half_len , 2);
}