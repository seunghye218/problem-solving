#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int odd = 0, even = 0;
    for (int &n : num_list) {
        int &num = n & 1 ? odd : even;
        num = num * 10 + n;
    }
    return odd + even;
}