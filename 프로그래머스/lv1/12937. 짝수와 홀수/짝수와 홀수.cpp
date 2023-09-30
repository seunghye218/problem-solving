#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    return string(num % 2 ? "Odd" : "Even");
}