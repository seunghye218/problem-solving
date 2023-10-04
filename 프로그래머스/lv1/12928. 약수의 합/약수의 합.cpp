#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    if (n == 0) return 0;
    int answer = 1 + n;
    int limit = int(sqrt(n)) + 1;
    for (int i = 2; i < limit; ++i) {
        if (n % i == 0) {
            answer += i + n / i;
        }
    }
    --limit;
    if (limit * limit == n)
        answer -= limit;
    return answer;
}