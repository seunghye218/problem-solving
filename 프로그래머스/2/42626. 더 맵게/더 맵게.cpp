#include <vector>
#include <set>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset m_set = multiset(scoville.begin(), scoville.end());
    
    while (m_set.size() > 1) {
        auto fir = m_set.begin(), sec = ++m_set.begin();
        if (*fir < K) {
            int mix = *fir + *sec * 2;
            m_set.erase(fir, ++sec);
            m_set.insert(mix);
            ++answer;
        } else {
            return answer;
        }
    }
    return *m_set.begin() < K ? -1 : answer;
}