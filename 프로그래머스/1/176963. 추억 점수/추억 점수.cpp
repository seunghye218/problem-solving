#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photos) {
    vector<int> answer;
    unordered_map<string, int> hash;
    for (int i = 0; i < name.size(); ++i)
        hash[name[i]] = yearning[i];
    for (auto &photo : photos) {
        int sum = 0;
        for (auto &name : photo)
            sum += hash[name];
        answer.push_back(sum);
    }
    return answer;
}