#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct coord { // 좌표
    int x, y;
    coord(int x, int y) : x(x), y(y) {}
    coord() : x(0), y(0) {}
    coord &operator=(const coord &a) { 
        x = a.x, y = a.y;
        return *this; 
    }
    coord operator+(coord &a) { return coord(x + a.x, y + a.y); }
    coord operator-(coord &a) { return coord(x - a.x, y - a.y); }
    bool operator==(coord &a) { return x == a.x && y == a.y; }
};

struct visited { // 방문한 간선
    coord ori, next;

    visited(coord a, coord b) { ori = a, next = b; }
    bool operator==(visited a) {
        return (ori == a.ori && next == a.next) ||
                (ori == a.next && next == a.ori);
    }
};

int solution(string dirs) {
    int answer = 0;
    vector<visited> v;
    coord pos(5,5); // init pos
    for (char c : dirs) {
        coord d;
        switch (c) {
            case 'D': d = {-1, 0}; break;
            case 'L': d = {0, -1}; break;
            case 'R': d = {0, 1}; break;
            case 'U': d = {1, 0}; break;
        }
        coord next = pos + d;
        if (next.y < 0 || next.x < 0 || next.y > 10 || next.x > 10)
            continue;
        visited tmp = {pos, next};
        if (find(v.begin(), v.end(), tmp) == v.end())
            v.push_back(tmp);
        pos = next;
    }
    return v.size();
}