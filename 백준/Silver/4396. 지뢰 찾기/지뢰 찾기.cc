#include <bits/stdc++.h>
using namespace std;

const int dx[3] = {-1, 0, 1};
const int dy[3] = {-1, 0, 1};

vector<string> get_map(int N);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<string> mine = get_map(N);
    vector<string> safe = get_map(N);

    bool is_fail = 0;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (mine[y][x] == '*') {
                if (safe[y][x] == 'x') {
                    is_fail = 1;
                    //continue;
                }

                for (int x2 : dx) {
                    for (int y2 : dy) {
                        int area_y = y + y2;
                        int area_x = x + x2;
                        if (area_y >= 0 && area_x >= 0 && area_y < N && area_x < N && safe[area_y][area_x] != '.' && mine[area_y][area_x] != '*') {
                            char &target = safe[area_y][area_x];
                            target == 'x' ? (target = '1') : (target += 1);
                        }
                    }
                }
            }
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (safe[y][x] == 'x') safe[y][x] = '0';
        }
    }

    if (is_fail) {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (mine[y][x] == '*') safe[y][x] = '*';
            }
        }
    }
    copy(safe.begin(), safe.end(), ostream_iterator<string>(cout, "\n"));
}

vector<string> get_map(int N) {
    vector<string> map(N);
    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        map[i] = line;
    }
    return map;
}
