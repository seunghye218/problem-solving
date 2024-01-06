#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string buf;
    istringstream ss(my_string);
    while (getline(ss, buf, ' '))
        answer.push_back(buf);
    return answer;
}