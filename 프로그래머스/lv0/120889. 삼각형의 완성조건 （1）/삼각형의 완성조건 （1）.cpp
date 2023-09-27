#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    struct Sum {
        void operator()(int n) { sum += n; }
        int sum {0};
    };
    Sum s = std::for_each(sides.cbegin(), sides.cend(), Sum());    
    int max = *max_element(sides.begin(), sides.end());
    return s.sum > max << 1 ? 1 : 2;
}