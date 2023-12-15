#include <numeric>
#include <vector>
using namespace std;

int solution(vector<int> num_list) {
    if (num_list.size() > 10)
        return accumulate(num_list.begin(), num_list.end(), 0);
    else
        return accumulate(num_list.begin(), num_list.end(), 1, multiplies<int>());
}