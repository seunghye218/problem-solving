#include <vector>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, area = 0;
    --m;
    for (int i = 0; i < section.size(); ++i)
        if (section[i] > area)
            (area = section[i] + m), ++answer;
    return answer;
}