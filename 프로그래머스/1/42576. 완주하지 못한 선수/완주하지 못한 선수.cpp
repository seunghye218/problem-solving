#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> p_map;
    unordered_map<string, int> c_map;
    
    for (auto p : participant)
        ++p_map[p];
    for (auto c : completion)
        ++c_map[c];
    for (auto p : p_map)
        if (p_map[p.first] != c_map[p.first])
            return p.first;
    return "";
}