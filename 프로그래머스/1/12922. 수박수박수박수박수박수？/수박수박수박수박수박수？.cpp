#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for (int i = 0; i < n; i++)
        i & 1 ? answer.append(u8"박") : answer.append(u8"수");
    return answer;
}