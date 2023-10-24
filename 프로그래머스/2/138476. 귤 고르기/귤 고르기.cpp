#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef unordered_map<int, int>::const_iterator iter;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> box;
    priority_queue<int>     cnt;
//  맵에 크기별로 카운트.
    for (int i = 0; i < tangerine.size(); ++i)
        ++box[tangerine[i]];
//  힙에 갯수 저장.
    for (iter it = box.begin(); it != box.end(); ++it)
        cnt.push(it->second);
//  많은 개수 부터 차감.
    while (k > 0) {
        k -= cnt.top();
        cnt.pop();
        ++answer;
    }
    return answer;
}