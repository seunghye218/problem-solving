#include <queue>
#include <algorithm>
using namespace std;

int arr[1000001];

struct dx {
    int d, x;
};

int solution(int x, int y, int n) {
    int answer = 987654321;
    queue<dx> q;
    
    q.push({0, x});
    while (!q.empty()) {
        dx d_x = q.front();
        q.pop();
        if (d_x.x == y)
            return d_x.d;
        if (d_x.x > y)
            continue;
        if (arr[d_x.x])
            if (d_x.d < arr[d_x.x])
                arr[d_x.x] = d_x.d;
            else
                continue;  
        else
            arr[d_x.x] = d_x.d;
        ++d_x.d;
        q.push({d_x.d, d_x.x * 3});
        q.push({d_x.d, d_x.x << 1});
        q.push({d_x.d, d_x.x + n});
    }
    return answer == 987654321 ? -1 : answer;
}