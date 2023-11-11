#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool solution(vector<string> pb) {
    sort(pb.begin(), pb.end());
    for (int i = 1; i < pb.size(); ++i)
        if (pb[i - 1] == pb[i].substr(0, pb[i - 1].size()))
            return false;
    return true;
}
