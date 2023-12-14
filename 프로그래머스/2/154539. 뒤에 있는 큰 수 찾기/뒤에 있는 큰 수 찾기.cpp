#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1); // -1로 초기화
    stack<pair<int, int>> st; // <원소 값, 인덱스>
    for (int i = 0, size = numbers.size(); i < size; ++i) {
        // 비어있지 않으며 && 스택의 top 보다 현재 숫자가 더 클 때
        if (!st.empty() && st.top().first < numbers[i]) {
            // 그보다 작은 스택의 원소들을 꺼내며 현재 숫자를 입력
            while (!st.empty() && st.top().first < numbers[i]) {
                answer[st.top().second] = numbers[i];
                st.pop();
           }
        }
        st.push({numbers[i], i});
    }
    return answer;
}