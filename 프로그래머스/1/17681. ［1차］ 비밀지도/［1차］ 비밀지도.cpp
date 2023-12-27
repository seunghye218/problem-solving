#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> map(n, string(n, ' '));
    for (int y = 0; y < n; ++y)
        for (int row = arr1[y] | arr2[y], x = n; x; --x, row >>= 1)
            if (1 & row) map[y][x - 1] = '#';
    return map;
}