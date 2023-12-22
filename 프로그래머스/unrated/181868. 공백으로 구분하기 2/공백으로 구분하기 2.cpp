#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(string str) {
    vector<string> answer;
    istringstream is(str.c_str());
    while (is >> str)
        answer.push_back(str);
    return answer;
}