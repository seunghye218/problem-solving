#include <string>
using namespace std;

int solution(string word) {
    string vowel = "AEIOU"; 
    int op[5] = {781, 156, 31, 6, 1}; // 문자 순서와 자리 순서에 따른 증가값
    int answer = word.size(); // 자릿수에 따른 기본값
    for (int i = 0; i < word.size(); ++i)
        answer += op[i] * vowel.find(word[i]);
    return answer;
}