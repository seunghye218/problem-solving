#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> scores) {
    priority_queue<int, vector<int>, greater<int>> heap;
    vector<int> answer;
    for (int &score : scores) {
        heap.push(score);
        if (heap.size() > k)
            heap.pop();
        answer.push_back(heap.top());
    }
    return answer;
}