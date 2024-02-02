#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    deque<int> basket;
    for (int &x : moves) {
        --x;
        int y = 0;
        while (y < board.size() && !board[y][x])
            ++y;
        if (y != board.size()) {
            basket.push_back(board[y][x]);
            board[y][x] = 0;
        }
    }
    if (basket.size() < 2)
        return 0;
    for (auto it = basket.begin() + 1; it != basket.end() && basket.size() > 1; ++it) {
        if (*it == *(it - 1)) {
            answer += 2;
            basket.erase((it - 1), it + 1);
            it = basket.begin();
        }
    }
    return answer;
}