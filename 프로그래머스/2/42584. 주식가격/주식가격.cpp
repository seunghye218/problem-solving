#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> st; // index 저장
    for (int i = 0; i < prices.size(); ++i) {
        if (st.empty()) {
            st.push(i);
        } else {
            if (prices[i] >= prices[st.top()]) { // 값이 커지면 push
                st.push(i);
            } else { // 값이 작다면 현재 index - 저장 index 반복
                while (!st.empty() && prices[st.top()] > prices[i]) {
                    answer[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
    }
    while (!st.empty()) {
        answer[st.top()] = prices.size() - 1 - st.top();
        st.pop();
    }
    return answer;
}