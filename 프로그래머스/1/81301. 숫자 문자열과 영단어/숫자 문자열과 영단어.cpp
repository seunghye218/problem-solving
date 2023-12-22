#include <regex>
using namespace std;

inline void replace(string &s, char *src, char *dst) {
    s = regex_replace(s, regex(src), dst);
}

int solution(string s) {
    replace(s, "zero", "0");
    replace(s, "one", "1");
    replace(s, "two", "2");
    replace(s, "three", "3");
    replace(s, "four", "4");
    replace(s, "five", "5");
    replace(s, "six", "6");
    replace(s, "seven", "7");
    replace(s, "eight", "8");
    replace(s, "nine", "9");    
    return stoi(s);
}