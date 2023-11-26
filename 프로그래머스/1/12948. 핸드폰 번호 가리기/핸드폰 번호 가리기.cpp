#include <string>
using namespace std;
string solution(string s) {
    for (int i = 0, end = s.size() - 4; i < end; ++i) s[i] = '*';
    return s;
}