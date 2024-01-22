#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n + 2);
    for (int l : lost)
        --v[l];
    for (int r : reserve)
        ++v[r];
    for (int i = 1; i <= n; ++i) {
        if (v[i] == -1) {
            if (v[i - 1] > 0) {
                --v[i - 1];
                ++answer;
            } else if (v[i + 1] > 0) {
                --v[i + 1];
                ++answer;
            }
        } else {
            ++answer;
        }
    }
    return answer;
}