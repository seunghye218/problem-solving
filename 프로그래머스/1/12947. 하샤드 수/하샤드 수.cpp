#include <vector>
using namespace std;

bool solution(int x) {
    int y = 0, x2 = x;
    while (x > 0) {
        y += x % 10;
        x /= 10;
    }
    return x2 % y ? 0 : 1;
}