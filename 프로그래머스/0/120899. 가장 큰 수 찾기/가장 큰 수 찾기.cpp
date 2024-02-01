#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    auto m = max_element(arr.begin(), arr.end());
    return {*m, (int)(m - arr.begin())};
}