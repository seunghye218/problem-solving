#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size();) {
        int n;
        switch (s[i]) {
            case 'e' : n = 8, i += 5; break;
            case 'f' :
                if (s[i+1] == 'o')
                    n = 4, i += 4;
                else
                    n = 5, i += 4;
                break;
            case 'n' : n = 9, i += 4; break;
            case 'o': n = 1, i += 3; break;
            case 's':
                if (s[i + 1] == 'i')
                    n = 6, i += 3;
                else
                    n = 7, i += 5;
                break;
            case 't':
                if (s[i + 1] == 'w')
                    n = 2, i += 3;
                else
                    n = 3, i += 5;
                break;
            case 'z': n = 0, i += 4; break;
            default : n = s[i] - '0', ++i;
        }
        answer = answer * 10 + n;
    }
    return answer;
}