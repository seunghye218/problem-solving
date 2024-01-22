#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> strArr) {
    for (int i = 0; i < strArr.size(); ++i) {
        if (i & 1)
            for (char &c : strArr[i])
                c &= ~32;
        else
            for (char &c : strArr[i])
                c |= 32;
    }
    return strArr;
}