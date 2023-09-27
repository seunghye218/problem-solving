#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    for_each(numbers.begin(), numbers.end(), [](int &i) { i *= 2; });
    return numbers;
}