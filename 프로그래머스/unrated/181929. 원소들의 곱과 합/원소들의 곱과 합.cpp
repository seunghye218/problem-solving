#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int sum, mul;
    sum = accumulate(num_list.begin(), num_list.end(), 0);
    mul = accumulate(num_list.begin(), num_list.end(), 1, [](const int & a, const int & b) {return a * b;});
    return mul < sum * sum ? 1 : 0;
}