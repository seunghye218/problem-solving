#include <numeric>
#include <vector>
using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int len1 = arr1.size(), len2 = arr2.size();
    if (len1 == len2) {
        len1 = accumulate(arr1.begin(), arr1.end(), 0);
        len2 = accumulate(arr2.begin(), arr2.end(), 0);
        if (len1 == len2)
            return 0;
    }
    return len1 > len2 ? 1 : -1;
}