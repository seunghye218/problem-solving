#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string myString) {
    int i = 0;
    myString += ' ';
    while (myString[i] != ' ') {
        myString[i] = toupper(myString[i]);
        ++i;
    }
    myString.pop_back();
    return myString;
}