#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution(vector<int> order) {
    queue<int> container;
    stack<int> second;
    for (int i = 1; i <= order.size(); ++i)
        container.push(i);
    
    int answer = 0;
    for (int n : order) {
        while (!container.empty() && n > container.front()) {
            second.push(container.front());
            container.pop();
        }
        if (n != container.front() && n != second.top())
            break;
        if (n == container.front())
            container.pop();
        else
            second.pop();
        ++answer;
    }
    return answer;
}


