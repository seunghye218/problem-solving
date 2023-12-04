#include <cmath>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (; left <= right; ++left) {
        double rt  = sqrt(left);
        if (rt == (int)rt)
            answer -= left;
        else
            answer += left;
    }
    return answer;
}