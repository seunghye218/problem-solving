#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1, n2 = n + 1; i < n2; ++i)
        if (!(n % i))
            ++answer;
    return answer;
}