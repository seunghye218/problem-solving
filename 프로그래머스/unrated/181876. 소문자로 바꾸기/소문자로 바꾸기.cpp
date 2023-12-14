#include <string>
using namespace std;

string solution(string myString) {
    for (char &c : myString) c |= 32;
    return myString;
}