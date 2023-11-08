#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> m;
    
    for (int i = 0; i < survey.size(); ++i) {
        int score = choices[i] - 4;
        if (score < 0)
            m[survey[i][0]] -= score;
        else
            m[survey[i][1]] += score;
    }
    answer += m['R'] >= m['T'] ? 'R' : 'T';
    answer += m['C'] >= m['F'] ? 'C' : 'F';
    answer += m['J'] >= m['M'] ? 'J' : 'M';
    answer += m['A'] >= m['N'] ? 'A' : 'N';
    return answer;
}