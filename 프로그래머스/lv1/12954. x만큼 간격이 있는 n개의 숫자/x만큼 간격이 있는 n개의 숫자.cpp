#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for (int i = 0, x2 = x; i < n; ++i) {
        answer.push_back(x2);
        x2 += x;
    }
    return answer;
}