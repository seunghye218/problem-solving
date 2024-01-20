#include <string>
#include <vector>
#include <queue>
using namespace std;

struct box {
    int x, y, n;
};

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    queue<box> q;
    q.push({0, 0, (int)arr[0].size()});
    while (!q.empty()) {
        bool is_same = true;
        box &b = q.front();
        if (b.n == 1) {
            ++answer[arr[b.y][b.x]];
        } else {
            for (int y = b.y; is_same && y < b.y + b.n; ++y) {
                for (int x = b.x; x < b.x + b.n; ++x) {
                    if (arr[b.y][b.x] != arr[y][x]) {
                        b.n >>= 1;
                        q.push({b.x, b.y, b.n});
                        q.push({b.x + b.n, b.y, b.n});
                        q.push({b.x, b.y + b.n, b.n});
                        q.push({b.x + b.n, b.y + b.n, b.n});
                        is_same = false;
                        break;
                    }
                }
            }
            if (is_same)
                ++answer[arr[b.y][b.x]];
        }
        q.pop();
    }
    return answer;
}