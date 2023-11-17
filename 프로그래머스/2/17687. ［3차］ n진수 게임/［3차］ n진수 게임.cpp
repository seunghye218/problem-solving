#include <string>
#include <vector>
using namespace std;

inline string to_str_base(int n, int p) {
    static const char base[17] = "0123456789ABCDEF";
    string  str = "";
    while (p > 0) {
        str = base[p % n] + str;
        p /= n;
    }
    return str;
}

string solution(int n, int t, int m, int p) {
    string tran = "0", answer = "";
    --p;
     // 문자열 길이(== 순서)가 끝 순서 까지 도달
    for (int i = 1, end = m * t + p; tran.size() < end;++i)
        tran += to_str_base(n, i);
    for (int i = p; t > 0; i += m, --t)
        answer += tran[i];
    return answer;
}