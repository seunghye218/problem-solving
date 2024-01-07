#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> scores(3, 0);
    int fir[5] = {1, 2, 3, 4, 5};
    int sec[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int thr[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for (int i = 0; i < answers.size(); ++i) {
        if (fir[i % 5] == answers[i]) ++scores[0];
        if (sec[i % 8] == answers[i]) ++scores[1];
        if (thr[i % 10] == answers[i]) ++scores[2];
    }
    int max = *max_element(scores.begin(), scores.end());
    vector<int> answer;
    for (int i = 0; i < scores.size(); ++i)
        if (max == scores[i])
            answer.push_back(i + 1);
    return answer;
}