#include <string>
using namespace std;

int solution(string t, string p) {
    int answer = 0, len = p.size();
    for (int i = 0, end = t.size() - len; i <= end; ++i) {
        if (t.substr(i, len) <= p)
            ++answer;
    }
    return answer;
}