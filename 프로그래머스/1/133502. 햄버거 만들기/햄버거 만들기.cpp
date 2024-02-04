#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    deque<int> Q;
    for (int &i : ingredient)
        Q.push_back(i);
    for (auto it = Q.begin() + 3; Q.size() > 3 && it != Q.end(); ++it) {
        if (*it == 1 && *(it-1) == 3 && *(it-2) == 2 && *(it-3) == 1) {
            ++answer;
            auto tmp = it - 4;
            Q.erase(it - 3, it + 1);
            if (Q.size() > 3)
                it = tmp;
            else
                break;
        }
    }
    return answer;
}