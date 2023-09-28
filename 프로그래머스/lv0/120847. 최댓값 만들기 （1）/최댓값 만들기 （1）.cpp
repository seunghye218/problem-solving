#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    vector<int>::iterator it = max_element(numbers.begin(), numbers.end());
    int max = *it;
    numbers.erase(it);
    return max * *max_element(numbers.begin(), numbers.end());
}