#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1); // -1로 초기화
    stack<int> st; // <인덱스>
    for (int i = 0, size = numbers.size(); i < size; ++i) {
        // 비어있지 않으며 && 스택의 top 보다 현재 숫자가 더 클 때
        if (!st.empty() && numbers[st.top()] < numbers[i]) {
            // 그보다 작은 스택의 원소들을 꺼내며 현재 숫자를 입력
            while (!st.empty() && numbers[st.top()] < numbers[i]) {
                answer[st.top()] = numbers[i];
                st.pop();
           }
        }
        st.push(i);
    }
    return answer;
}