#include <string>
#include <algorithm>
using namespace std;

int solution(int a, int b) {
    string str_a = to_string(a), str_b = to_string(b);
    return max(stoi(str_a + str_b), stoi(str_b + str_a));
}