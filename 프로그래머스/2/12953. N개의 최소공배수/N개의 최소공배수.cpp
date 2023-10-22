#include <vector>
#include <map>
#include <numeric>
#include <cmath>
using namespace std;

#define MAX_NUM 100

inline bool is_prime(const int &n);
inline int cnt_prime_factor(int &n, const int &div);

// 배열의 모든 원소를 소수로 나누며 1이 되면 erase
int solution(vector<int> arr) {
    int i, j, answer = 1;
    map<int, int>   prime_factors;
    
    while (arr.size()) {
        for (i = 2; i < MAX_NUM; ++i) {
            if (is_prime(i)) {
                int &cnt_prime = prime_factors[i];
                for (int j = 0; j < arr.size(); ++j) {
                    cnt_prime = max(cnt_prime, cnt_prime_factor(arr[j], i));
                    if (arr[j] == 1) {
                        arr.erase(arr.begin() + j);
                        --j;
                    }
                }
            }
        }
    }
    for (map<int, int>::iterator it = prime_factors.begin();
        it != prime_factors.end(); ++it)
            answer *= int(pow(it->first, it->second));
    return answer;
}

inline bool is_prime(const int &n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

inline int cnt_prime_factor(int &n, const int &div) {
    int cnt = 0;
    while (n % div == 0) {
        n /= div;
        ++cnt;
    }
    return cnt;
}