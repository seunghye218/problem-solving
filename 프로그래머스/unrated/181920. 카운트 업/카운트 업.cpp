#include <vector>
using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer;
    for (; start_num <= end_num; ++start_num)
        answer.push_back(start_num);
    return answer;
}