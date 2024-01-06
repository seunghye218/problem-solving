#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> scores) {
    int answer = 0, size = scores.size();
    if (m > size)
        return 0;
    sort(scores.begin(), scores.end());
    for (int i = size % m; i < size; i += m)
        answer += scores[i] * m;
    return answer;
}