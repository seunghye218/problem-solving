#include <string>
#include <numeric>
using namespace std;

int solution(string dartResult) {
    string_view sv = dartResult;
    int score[3];
    int i = -1;
    while (sv.size()) {
        switch (sv.front()) {
            case 'D' : 
                score[i] = score[i] * score[i]; 
                break;
            case 'S' :
                break;
            case 'T' :
                score[i] = score[i] * score[i] * score[i]; break;
            case '*' :
                if (i) score[i-1] <<= 1;
                score[i] <<= 1;
                break;
            case '#' :
                score[i] *= -1; break;
            default :
                size_t pos;
                score[++i] = stoi(string(sv), &pos);
                if (pos == 2) sv.remove_prefix(1);
        }
        sv.remove_prefix(1);
    }
    return accumulate(score, score + 3, 0);
}
