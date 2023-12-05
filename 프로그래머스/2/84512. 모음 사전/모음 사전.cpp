#include <string>
using namespace std;

int solution(string word) {
    int op[5] = {781, 156, 31, 6, 1}; // 문자 순서와 자리 순서에 따른 증가값
    int answer = word.size(); // 자릿수에 따른 기본값
    for (int i = 0; i < word.size(); ++i) {
        int index;
        switch (word[i]) {
            case 'A' : index = 0; break;
            case 'E' : index = 1; break;
            case 'I' : index = 2; break;
            case 'O' : index = 3; break;
            case 'U' : index = 4; break;
        }
        answer += op[i] * index;
    }
    return answer;
}