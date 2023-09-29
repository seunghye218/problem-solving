#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    return string::npos != str1.find(str2) ? 1 : 2;
}