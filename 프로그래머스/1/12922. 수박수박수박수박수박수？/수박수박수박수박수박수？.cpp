#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    answer.reserve(n*2);
    for (int i = 0; i < n; i++)
        if (i & 1) answer.append(u8"박");
        else answer.append(u8"수");
    return answer;
}