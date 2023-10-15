#include <string>
#include <vector>

using namespace std;

int solution(const int n) {
    int answer = 0, i = 0, tmp1 = 0, tmp2  = 1;
    while (++i < n) {
        answer = tmp1;
        answer += tmp2;
        tmp1 = tmp2;
        answer %= 1234567;
        tmp2 = answer;
    }
    return answer;
}