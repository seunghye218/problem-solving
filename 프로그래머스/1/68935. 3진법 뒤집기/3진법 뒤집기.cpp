#include <string>
using namespace std;

int solution(int n) {
    string str = "";
    while (n > 0) {
        str.push_back('0' + n % 3);
        n /= 3;
    }
    return stoi(str, 0, 3);
}