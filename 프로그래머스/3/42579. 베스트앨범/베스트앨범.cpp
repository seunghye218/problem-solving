#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
//  key: 장르    value: <vec<고유번호, plays>>, play 합계>>
    map<string, pair<vector<pair<int, int>>, int>>    genres_map;
//  장르를 키값으로 장르 벡터<고유번호, play> 와 합계를 동시에 생성
    for (int i = 0; i < genres.size(); ++i) {
        genres_map[genres[i]].first.push_back(pair(i, plays[i]));
        genres_map[genres[i]].second += plays[i];
    }
//  key: play 합계    value: vec<고유번호, play>>>
    map<int, vector<pair<int, int>>>    sorted_g;
//  생성된 맵에서 play 합계를 기준으로 정렬된 맵 생성 (장르 문자열은 필요 없음)
    for (auto it = genres_map.begin(); it != genres_map.end(); ++it) {
        sorted_g[it->second.second] = it->second.first;
    }
//  reverse_iterator 를 통해 play 합계 내림차순으로 2곡 선별
    for (auto it = sorted_g.rbegin(); sorted_g.size() && it != sorted_g.rend(); ++it) {
        auto tmp = max_element(it->second.begin(), it->second.end(), // 1st song
                   [](const auto &a, const auto &b) {return a.second < b.second;});
        answer.push_back(tmp->first);
        it->second.erase(tmp);
        tmp = max_element(it->second.begin(), it->second.end(), // 2cd song
                   [](const auto &a, const auto &b) {return a.second < b.second;});
        if (tmp != it->second.end())
            answer.push_back(tmp->first);
    }
    return answer;
}