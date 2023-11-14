#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    double answer = sqrt(n);
    return answer == int(answer) ? pow(answer+1, 2) : -1;
}