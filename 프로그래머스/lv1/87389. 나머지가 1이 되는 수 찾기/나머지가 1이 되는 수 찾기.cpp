#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    for (int i = 2, end = n / 2; i < end ;++i)
        if (n % i == 1)
            return i;
    return n - 1;
}