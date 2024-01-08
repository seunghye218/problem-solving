#include <string>
using namespace std;

string solution(string str) {
    for (char &c : str)
        c ^= 32;
    return str;
}