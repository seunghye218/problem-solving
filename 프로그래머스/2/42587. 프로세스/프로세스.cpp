#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int max, answer = 0, location_prior = priorities[location];
    queue<pair<int, int>>   prior_qu;
    priority_queue<int>     heap;

    for (int i = 0; i < priorities.size(); ++i) {
        heap.push(priorities[i]);
        prior_qu.push({priorities[i], i});
    }
    while (true) {
        max = heap.top();
        if (prior_qu.front().first != max)
            prior_qu.push(prior_qu.front());
        else {
            heap.pop();
            ++answer;
            if (prior_qu.front().second == location)
                break;
        }
        prior_qu.pop();
    }
    return answer;
}