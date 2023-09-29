#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (string::iterator it = my_string.begin();
        it != my_string.end();
        ++it)
        if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u')
            continue;
        else
            answer += *it;
    return answer;
}