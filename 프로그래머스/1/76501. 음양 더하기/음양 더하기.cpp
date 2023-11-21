#include <vector>
using namespace std;
int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0, end = signs.size(); i < end; ++i) {
        if (signs[i]) answer += absolutes[i];
        else answer -= absolutes[i];
    }
    return answer;
}