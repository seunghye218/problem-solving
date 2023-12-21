#include <string>
using namespace std;

#define ALPHA_SIZE 26
#define LOWER_BIT 32

string solution(string s, int n) {
    for (char &c : s) {
        if (c != ' ') {
            if ((c | LOWER_BIT) + n > 'z') {
                c -= ALPHA_SIZE;
            }
            c += n;
        }
    }
    return s;
}