#include <string>
using namespace std;

int solution(string s) {
    int answer = 0;
    for (auto it = s.begin(); it != s.end();) {
        char c = *it;
        int cnt = 1;
        while (++it != s.end() && cnt)
            c == *it ? ++cnt : --cnt;
        ++answer;
    }
    return answer;
}