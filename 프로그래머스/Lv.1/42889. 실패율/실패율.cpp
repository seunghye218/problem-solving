#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct stage {
    int n, fail, reach;
};

vector<int> solution(int N, vector<int> stages) {
    // count staying stage
    map<int, int> stage_count;
    for (int &stage : stages)
        ++stage_count[stage];
    // set fail, reach
    vector<stage> fail_rate(N + 1);
    fail_rate.push_back({1, stage_count[1], (int)stages.size()});
    for (int i = 2; i < N + 1; ++i) {
        fail_rate.push_back({
            i,
            stage_count[i],
            fail_rate.back().reach - fail_rate.back().fail
            });
    }
    // sort by failure rate
    stable_sort(fail_rate.begin(), fail_rate.end(), [](auto a, auto b) {
        return (float)a.fail / a.reach > (float)b.fail / b.reach;
    });
    // set answer
    vector<int> answer;
    for (auto stage : fail_rate)
        if (stage.n)
            answer.push_back(stage.n);
    return answer;
}