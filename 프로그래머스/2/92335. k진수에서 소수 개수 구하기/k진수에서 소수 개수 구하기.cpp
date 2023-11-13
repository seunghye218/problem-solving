#include <string>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

bool is_prime(string s) {
    long long n = stol(s);
    if (n < 2)
        return false;
    int rt = sqrt(n);
    for (int i = 2; i <= rt; ++i)
        if (n % i == 0)
            return false;
    return true;
}

void get_k_base_string(long long div, string& str, const int &n,const int &k) {
    if (n / div == 0) return;
    get_k_base_string(div * k, str, n, k);
    str += (n / div) % k + '0';
}

int solution(int n, int k) {
    int answer = 0;
    string str = "";
    get_k_base_string(1, str, n, k); // k진수 문자열
    stringstream ss(str);
    while (getline(ss, str, '0')) // 0 기준 split
        if (!str.empty() && is_prime(str))
            ++answer;
    return answer;
}