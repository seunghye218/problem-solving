#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    for (long long &n : numbers) {
        long long bit = 1;
        while (n & bit) 
            bit <<= 1;
        n = (n | bit) & ~(bit >> 1);
    }
    return numbers;
}