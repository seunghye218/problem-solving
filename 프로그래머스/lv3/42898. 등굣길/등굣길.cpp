#include <string>
#include <vector>
using namespace std;

inline bool    is_puddles(const int &m, const int &n, const vector<vector<int>> &puddles) {
    for (int i = 0; i < puddles.size(); ++i)
        if (puddles[i][0] == m && puddles[i][1] == n)
            return true;
    return false;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i = 0; i < puddles.size(); ++i)
        --puddles[i][0], --puddles[i][1];
    
    map[0][0] = 1;
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            if (is_puddles(x, y, puddles)) continue ;
            int s = 0;
            if (y) s += map[y - 1][x];
            if (x) s += map[y][x - 1];
            map[y][x] += s % 1000000007;
        }
    }
    return map[n - 1][m - 1];
}
