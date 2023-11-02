#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

typedef string::const_iterator iter;

vector<int> get_vec(iter begin, iter end) {
    vector<int>   vec;
    stringstream ss(string(begin, end));
    string  token;

    while (getline(ss, token, ','))
        vec.push_back(stoi(token));        
    return vec;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, vector<int>>   sort_map;
        
    for (iter it = s.begin() + 1, end = s.end() - 2; it < end; ++it) {
            ++it; // ','+1
            iter set_end = it;
            while (*++set_end != '}');
            vector<int> vec = get_vec(it, set_end);
            sort_map[vec.size()] = vec;
            it = ++set_end; // ','
    }
    for (int i = 1; i <= sort_map.size(); ++i) {
        for (int j = 0; j < sort_map[i].size(); ++j)
            if (find(answer.begin(), answer.end(), sort_map[i][j]) == answer.end()) {
                answer.push_back(sort_map[i][j]);
                break;
            }
    }
    return answer;
}