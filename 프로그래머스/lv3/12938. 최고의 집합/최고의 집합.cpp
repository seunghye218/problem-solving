#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int s) {
//  집합이 존재하지 않는 경우
    if (n > s)
        return vector<int>(1, -1);

    vector<int> answer(n, s / n);
    for (int i = 0, end = s % n; i < end; ++i)
        ++*(answer.rbegin() + i);
    return answer;
}