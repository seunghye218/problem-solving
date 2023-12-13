#include <vector>
using namespace std;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    answer[0] = gcd(n, m);
    answer[1] = n * m / answer[0];
    return answer;
}