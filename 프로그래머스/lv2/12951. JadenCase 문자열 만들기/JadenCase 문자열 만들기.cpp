#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    bool first = true;
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (*it == ' ') {
            first = true;
        } else if (first) {
            *it = toupper(*it);
            first = false;
        }
        else {
            *it = tolower(*it);
        }
    }
    return s;
}