#include <string>
using namespace std;

string solution(string s) {
    int i = 0;
    for (char &c : s) {
        if (!isalpha(c)) {
            i = 0;
        } else {
            i & 1 ? c |= 32 : c &= ~32;
            ++i;
        }
    }
    return s;
}