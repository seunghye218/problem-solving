#include <cmath>
long long solution(int a, int b) {
    return (a + b) / 2.0 * (abs(b-a) + 1);
}