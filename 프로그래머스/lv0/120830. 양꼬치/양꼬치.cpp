#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int service = 0;
    service = n / 10;
    k = (k - service) < 0 ? 0 : k - service;
    return n * 12000 + k * 2000;
}