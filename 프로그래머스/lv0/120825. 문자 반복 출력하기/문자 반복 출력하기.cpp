#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    my_string += "";
    const char *str = my_string.c_str();
    while (*str) {
        for (int i = 0; i < n; ++i) 
            answer += *str;
        ++str;
    }
    return answer;
}