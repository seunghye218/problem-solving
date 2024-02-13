#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    for(int i = 1; i <= order.size(); ++i) {
        st.push(i);
        while(!st.empty() && order[answer] == st.top()) {
            st.pop();
            answer++;
        }
    }
    return answer;
}


