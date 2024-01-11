#include <string>
using namespace std;

int solution(string myString, string pat) {
    for (char &c : myString)
        c |= 32;
    for (char &c : pat)
        c |= 32;
    return myString.find(pat) != -1;
}