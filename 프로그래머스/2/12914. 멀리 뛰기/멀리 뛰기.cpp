#include <string>
#include <vector>

using namespace std;

// 피보나치 수열
long long solution(int n) {
    long long answer = 0, tmp1 = 0, tmp2 = 1;
    int tmp = n;
    while (n) {
//      f(n) = f(n-1) + f(n-2)
        answer = (tmp1 + tmp2)  % 1234567;
        tmp1 = tmp2;
        tmp2 = answer;
        --n;
    }
    return answer;
}