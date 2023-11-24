#include <vector>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 45; // sum(0~9)
    for (int n : numbers) answer -= n;
    return answer;
}