#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for (vector<string>::iterator i = s1.begin(), end = s1.end();
        i != end;
        ++i) {
        if (s2.end() != find(s2.begin(), s2.end(), *i)) ++answer;   
    }
    return answer;
}