#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> lst, int n) {
    return find(lst.begin(), lst.end(), n) == lst.end() ? 0 : 1;
}