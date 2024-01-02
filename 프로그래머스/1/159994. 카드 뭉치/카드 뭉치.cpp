#include <string>
#include <vector>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    auto i = cards1.begin(), j = cards2.begin();

    for (string &word : goal) {
        if (*i == word)
            ++i;
        else if (*j == word)
            ++j;
        else
            return "No";
    }
    return "Yes";
}