#include <vector>
using namespace std;

int solution(int n) {
    static std::vector<bool> is_prime(1000001, true);
    if (is_prime[0]) {
        for (int i = 2; i <= 1000001; i++)
            if (is_prime[i])
              for (int j = i + i; j <= 1000001; j += i)
                is_prime[j] = false;
        is_prime[0] = false;
    }
    int answer = 0;
    for (int i = 2; i <= n; ++i)
        if (is_prime[i])
            ++answer;
    return answer;
}