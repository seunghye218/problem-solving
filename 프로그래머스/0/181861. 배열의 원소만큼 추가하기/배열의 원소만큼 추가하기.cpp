#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for (int n : arr)
        answer.insert(answer.end(), n, n);
    return answer;
}