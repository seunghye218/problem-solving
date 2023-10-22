#include <iostream>

using namespace std;

// 이겼을 때 2로 나눈 몫이 번호가 됨.(번호가 0부터 시작된다면)
int solution(int n, int a, int b)
{
    int answer = 1;
//  번호가 0부터 시작된다고 가정
    --a, --b;
    while (a>>1 != b>>1) {
        a >>= 1;
        b >>= 1;
        ++answer;
    }
    return answer;
}