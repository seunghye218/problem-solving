#include <queue>
#include <algorithm>
using namespace std;

int dp[1000001];

struct dx {
    int d, x;
};

int solution(int x, int y, int n) {
    queue<dx> q;
    q.push({0, x});
    while (!q.empty()) {
        dx d_x = q.front();
        q.pop();
        if (d_x.x == y)
            return d_x.d;
        if (d_x.x > y || (dp[d_x.x] && d_x.d > dp[d_x.x]))
            continue;
        dp[d_x.x] = d_x.d;
        ++d_x.d;
        q.push({d_x.d, d_x.x * 3});
        q.push({d_x.d, d_x.x << 1});
        q.push({d_x.d, d_x.x + n});
    }
    return -1;
}