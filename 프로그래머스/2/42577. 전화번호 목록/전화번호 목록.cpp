#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool solution(vector<string> pb) {
    sort(pb.begin(), pb.end());
    unordered_set<string> pb_set;
    pb_set.insert(pb.begin(), pb.end());
    for (int i = pb.size()-1; i > 0; --i) {
        auto it = pb_set.find(pb[i]);
        string str(*it);
        pb_set.erase(it);
        for (int j = 1; j < str.size(); ++j)
            if (pb_set.find(str.substr(0,j)) != pb_set.end())                  return false;
    }
    return true;
}
