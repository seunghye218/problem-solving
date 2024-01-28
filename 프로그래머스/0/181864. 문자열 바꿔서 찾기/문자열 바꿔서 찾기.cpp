#include <string>
using namespace std;

int solution(string myString, string pat) {
    for (char &c : pat)
        c == 'A' ? ++c : --c;
    return myString.find(pat) != -1;
}