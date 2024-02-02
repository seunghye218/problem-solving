#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> nums) {
    sort(nums.begin(), nums.end());
    return max(nums[0] * nums[1], nums.back() * *(nums.end() - 2));
}