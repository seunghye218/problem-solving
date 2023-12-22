#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> old;
    unordered_map<int, int> young;
    for (int &n : topping)
        ++young[n];
    for (int &n : topping) {
        ++old[n];
        --young[n];
        if (young[n] == 0)
            young.erase(n);
        if (old.size() == young.size())
            ++answer;
    }
    return answer;
}