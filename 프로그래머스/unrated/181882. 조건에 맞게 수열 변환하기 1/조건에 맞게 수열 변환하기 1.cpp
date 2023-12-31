#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    for (int &n : arr) {
        if (n >= 50 && !(n & 1))
            n >>= 1;
        else if (n < 50 && n & 1)
            n <<= 1;
    }
    return arr;
}