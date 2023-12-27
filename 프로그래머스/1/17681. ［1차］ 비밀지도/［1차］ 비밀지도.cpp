#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> map(n, "");
    for (int y = 0; y < n; ++y)
        for(int x = 0; x < n; ++x, arr1[y] >>= 1, arr2[y] >>= 1)
            map[y] = (1 & arr1[y] || 1 & arr2[y] ? '#' : ' ') + map[y];
    return map;
}