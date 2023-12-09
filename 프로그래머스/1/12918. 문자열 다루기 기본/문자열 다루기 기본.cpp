#include <string>
#include <regex>
using namespace std;

bool solution(string s) {
    return (s.size() == 4 || s.size() == 6) && regex_match(s, regex("^[0-9]+$"));
}