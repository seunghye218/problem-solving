#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> numbers, int target) {
    queue<pair<int, int>> q; // index, sum
    int answer = 0;
    // init
    q.push({1, numbers[0]});
    q.push({1,-numbers[0]});
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        if (p.first == numbers.size()) { // end
            if (p.second == target) // result
                ++answer;
        } else {
            q.push({p.first+1, p.second + numbers[p.first]});
            q.push({p.first+1, p.second - numbers[p.first]});
        }
    }
    return answer;
}