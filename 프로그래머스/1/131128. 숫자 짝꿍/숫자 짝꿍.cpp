#include <string>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    sort(X.begin(), X.end(), greater<char>());
    sort(Y.begin(), Y.end(), greater<char>());
    for (auto xi = X.begin(), yi = Y.begin();
         xi != X.end() && yi != Y.end();) {
        if (*xi == *yi) {
            answer += *xi;
            ++xi, ++yi;
        } else if (*xi > *yi) {
            ++xi;
        } else {
            ++yi;
        }
    }
    if (answer.size() == 0)
        return "-1";
    if (answer[0] == '0')
        return "0";
    return answer;
}