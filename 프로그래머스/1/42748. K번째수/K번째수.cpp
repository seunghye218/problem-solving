#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto &cmd : commands) {
        vector<int> sub_vec(arr.begin() + cmd[0] - 1, 
                            arr.begin() + cmd[1]);
        sort(sub_vec.begin(), sub_vec.end());
        answer.push_back(sub_vec[cmd[2] - 1]);
    }
    return answer;
}