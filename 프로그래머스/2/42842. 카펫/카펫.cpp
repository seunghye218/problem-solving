#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 1);
    int w, h;
    for (h = 1; h * h <= yellow; ++h) {
        if (yellow % h == 0) {
            w = yellow / h;
            if (brown == (4 + (w << 1) + (h << 1))) {
                answer[0] = w + 2;
                answer[1] = h + 2;
                return answer;
            }
        }
    }
    return answer;
}