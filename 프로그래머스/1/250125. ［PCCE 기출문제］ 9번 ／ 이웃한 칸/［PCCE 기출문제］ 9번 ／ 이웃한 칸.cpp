#include <bits/stdc++.h>
using namespace std;

int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};
int visited[11][11];

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0, h_max = board.size(), w_max = board[0].size();
    string color = board[h][w];
    visited[h][w] = true;
    for (int i = 0; i < 4; ++i) {
        int h2 = h + dh[i];
        int w2 = w + dw[i];
        if (h2 >= 0 && w2 >= 0 && h2 < h_max && w2 < w_max &&
            board[h2][w2] == color && !visited[h2][w2])
            ++answer;
    }
    return answer;
}
