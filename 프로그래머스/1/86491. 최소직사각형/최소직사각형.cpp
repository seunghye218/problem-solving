#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int x = 0, y = 0;
    for (auto &size : sizes) {
        x = max(x, max(size[0], size[1]));
        y = max(y, min(size[0], size[1]));
    }
    return x * y;
}