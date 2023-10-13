#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
//       key: 장르
//       value: <vec<고유번호, plays>>, play 합계>>
    map<string, pair<vector<pair<int, int>>, int>>    genres_map;

    for (int i = 0; i < genres.size(); ++i) {
        genres_map[genres[i]].first.push_back(pair(i, plays[i]));
        genres_map[genres[i]].second += plays[i];
    }
//       key: play 합계
//       value: vec<고유번호, play>>>
    map<int, vector<pair<int, int>>>    sorted_g;
    for (auto it = genres_map.begin(); it != genres_map.end(); ++it) {
        sorted_g[it->second.second] = it->second.first;
    }

    for (auto it = sorted_g.rbegin(); sorted_g.size() && it != sorted_g.rend(); ++it) {
        auto tmp = max_element(it->second.begin(), it->second.end(), 
                   [](const auto &a, const auto &b) {return a.second < b.second;});
        answer.push_back(tmp->first);
        it->second.erase(tmp);
        tmp = max_element(it->second.begin(), it->second.end(), 
                   [](const auto &a, const auto &b) {return a.second < b.second;});
        if (tmp != it->second.end())
            answer.push_back(tmp->first);
    }
    return answer;
}