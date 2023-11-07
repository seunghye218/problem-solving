#include <vector>
#include <algorithm>
using namespace std;

void    bf(int i, int depth, int &answer,int k, vector<bool> visited, const vector<vector<int>> &dungeons) {
    ++depth;
    for (int j = 0; j < dungeons.size(); ++j) {
        if (!visited[j] && k >= dungeons[j][0]) {
            vector<bool> visited2(visited);
            visited2[j] = true;
            bf(j, depth, answer, k - dungeons[j][1], visited2, dungeons);
        } else
            answer = max(answer,depth);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    for (int i = 0; i < dungeons.size(); ++i) {
        vector<bool> visited(dungeons.size());
        if (k >= dungeons[i][0])
            visited[i] = true;
            bf(i, 0, answer, k - dungeons[i][1], visited, dungeons);
    }
    return answer;
}