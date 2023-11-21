#include <vector>
using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    while (n != 1) {
        if (n & 1 == 1) n = n * 3 + 1;
        else n >>= 1;
        ++answer;
    }
    return answer > 500 ? -1 : answer;
}