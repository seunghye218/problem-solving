#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if (n % 2) --n;
    while (n > 0) {
        answer += n;
        n -= 2;
    }
    return answer;
}