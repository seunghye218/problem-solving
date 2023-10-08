#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// 야근 피로도 계산
long long   get_sum_power(const vector<int> &works) {
    long long answer = 0;
    for (int j = 0; j < works.size(); ++j)
        answer += works[j] * works[j];
    return answer;
}

// 내림차순 정렬 후 가장 큰 값들 중 가장 뒤에 있는 인덱스 부터 앞쪽으로 차감
long long solution(int n, vector<int> works) {
    int i = 0;
    sort(works.rbegin(), works.rend());
    while (n) {
        while (i + 1 < works.size() && works[i] == works[i + 1])
            ++i;
        while (i != -1 && n) {
            if (works[i]) --works[i];
            --n;
            --i;
        }
        i = 0;
    }
    return get_sum_power(works);
}