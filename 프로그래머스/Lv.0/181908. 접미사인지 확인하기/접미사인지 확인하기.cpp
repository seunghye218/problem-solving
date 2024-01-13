#include <string>
using namespace std;

int solution(string str, string suffix) {
    int i = str.rfind(suffix);
    return i != -1 && i == str.size() - suffix.size();
}