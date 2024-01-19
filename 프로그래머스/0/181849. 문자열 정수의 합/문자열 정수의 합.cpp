#include <string>
#include <numeric>
using namespace std;

int solution(string num_str) {
    return accumulate(num_str.begin(), num_str.end(), 0, 
          [](int &n, char &c) { return n += c - '0'; });
}