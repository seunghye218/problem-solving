#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(2,0);
    for (vector<int>::iterator i = num_list.begin(), end = num_list.end();
        i != end;
        ++i) {
        if (*i % 2) ++answer[1];
    }
    answer[0] = num_list.size() - answer[1];
    return answer;
}