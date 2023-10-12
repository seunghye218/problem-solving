#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define APART_MAX 2147483646

int solution(int n, vector<int> stations, int w) {
    int answer = 0, range = (w << 1) + 1;
//  add station end
    stations.push_back(APART_MAX);
    ++n;
    for (int apart = 1, i = 0; apart < n;) {
//         station 범위 전 - apart + w 에 설치 가정 후 범위 패스.
        if (apart < stations[i] - w) {
            apart += range;
            ++answer;
//         station 범위 안 - 전파 범위 1 칸 뒤로 패스.
        } else {
            apart = stations[i] + w + 1;
            ++i;
        }
    }
    return answer;
}