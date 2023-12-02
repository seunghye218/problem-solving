#include <string>
using namespace std;

string solution(string my_string, int k) {
    string answer;
    answer.reserve(my_string.size() * k);
    while (--k >= 0) answer += my_string;
    return answer;
}