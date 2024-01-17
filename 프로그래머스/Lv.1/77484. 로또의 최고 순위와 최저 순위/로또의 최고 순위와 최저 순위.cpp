#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    bool nums[46] = {};
    for (int &n : win_nums)
        nums[n] = true;
    int doodles = 0;
    int wins = 0;
    for (int &n : lottos) {
        if (n == 0)
            ++doodles;
        else
            if (nums[n])
                ++wins;
    }
    return {7 - doodles - wins - (doodles + wins ? 0 : 1),
            7 - wins - (!wins ? 1 : 0)};
}