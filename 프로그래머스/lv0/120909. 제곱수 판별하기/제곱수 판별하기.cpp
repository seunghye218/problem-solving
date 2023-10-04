#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    float sqr = sqrt(n);
    return sqr == int(sqr) ? 1 : 2;
}