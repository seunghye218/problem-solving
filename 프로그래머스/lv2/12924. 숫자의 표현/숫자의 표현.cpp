#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, i = 1, j, sum;
    while (i <= n) {
        sum = 0;
        j = i;
        while (sum < n) {
            sum += j;
            ++j;
        }
        if (sum == n) ++answer;
        ++i;
    }
    return answer;
}