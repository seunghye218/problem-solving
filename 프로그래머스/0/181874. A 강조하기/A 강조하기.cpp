#include <string>
using namespace std;

string solution(string myString) {
    for (char &c : myString)
        if (c == 'a')
            c = 'A';
        else if (c != 'A')
            c |= 32;
    return myString;
}