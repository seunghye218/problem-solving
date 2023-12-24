#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), 
        [&n](string &s1, string &s2) {
            if (s1[n] == s2[n])
                return s1 < s2;
            return s1[n] < s2[n];
        });
    return strings;
}