#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int deploy, day;
    
    for (int i = 0; i < progresses.size(); i += deploy) {
        // 맨 앞 작업 처리
        day = (99 - progresses[i]) / speeds[i] + 1;
        deploy = 1;
        // 앞 작업 처리 중 처리된 뒷 작업
        while (i + deploy < progresses.size() && 
              progresses[i + deploy] + speeds[i + deploy] * day >= 100)
            ++deploy;
        answer.push_back(deploy);
    }
    return answer;
}