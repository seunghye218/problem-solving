#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    stringstream ss(myString);
    string token;
    while (getline(ss, token, 'x'))
        answer.push_back(token.size());
    if (myString.back() == 'x')
        answer.push_back(0);
    return answer;
}