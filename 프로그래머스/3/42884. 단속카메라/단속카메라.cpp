#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0, cam = -30001;
    sort(routes.begin(), routes.end(), [](const auto &i, const auto &j) {
        return i[1] < j[1];
    });
    
    for (const auto &range : routes) {
        if (cam < range[0]) {
            ++answer;
            cam = range[1];
        }
    }
    return answer;
}