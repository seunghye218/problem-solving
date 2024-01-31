#include <vector>
using namespace std;

int solution(vector<int> arr, int idx) {
    int answer = idx;
    for (; idx < arr.size() && !arr[idx]; ++idx);
    return idx == arr.size() ? -1 : idx;
}