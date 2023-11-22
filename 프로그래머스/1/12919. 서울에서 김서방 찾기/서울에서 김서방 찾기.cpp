#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> v) {
    return "김서방은 " +
        to_string(find(v.begin(), v.end(), "Kim") - v.begin()) +
        "에 있다";
}