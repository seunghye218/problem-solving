#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for (vector<string>::iterator i = strlist.begin(), end = strlist.end();
        i != end;
        ++i) {
        answer.push_back(i->size());
    }
    return answer;
}