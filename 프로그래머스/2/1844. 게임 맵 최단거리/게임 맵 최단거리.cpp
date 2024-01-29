#include <vector>
#include <queue>
using namespace std;

struct coord { int x, y, d; };

static const int dx[4] = {1, 0, -1, 0};
static const int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> maps) {
    int n = maps[0].size() - 1, m = maps.size() - 1;
    queue<coord> q;
    q.push({0, 0, 1});
    while (!q.empty()) {
        coord c = q.front();
        q.pop();
        if (c.x == m && c.y == n)
            return c.d;
        for (int i = 0; i < 4; ++i) {
            int x = c.x + dx[i];
            int y = c.y + dy[i];
            if (x >= 0 && x <= m && y >= 0 && y <= n && maps[x][y]) {
                maps[x][y] = false;
                q.push({x, y, c.d + 1});
            }
        }
    }
    return -1;
}