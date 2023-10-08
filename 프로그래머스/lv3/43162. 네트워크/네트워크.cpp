#include <string>
#include <vector>

using namespace std;

void    dfs(const int &x, const int &n, 
            const vector<vector<int>> &computers, 
            vector<bool> &visited);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
//          i 컴퓨터를 방문 안했으면 연결된 모든 컴퓨터 방문 처리
        if (visited[i] == false) {
            dfs(i, n, computers, visited);
            ++answer;
        }
    }
    return answer;
}

void    dfs(const int &x, const int &n, 
            const vector<vector<int>> &computers, 
            vector<bool> &visited) {
    visited[x] = true;
    for (int i = 0; i < n; ++i) {
        if (i != x &&               // 자신을 제외하고
            computers[x][i] == 1 && // 연결 되어있으며
            visited[i] == false) {  // 방문하지 않았을 때
            dfs(i, n, computers, visited);
        }
    }
}