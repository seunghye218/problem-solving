#include <string>
using namespace std;
bool solution(string s)
{
    int p = 0, y = 0;
    for (int i = 0; i < s.size(); ++i) {
        // 소문자와 대문자는 0b100000(== 32)비트 차이
        if ((s[i] | 32) == 'p') ++p;
        if ((s[i] | 32) == 'y') ++y;
    }
    return !(p - y);
}