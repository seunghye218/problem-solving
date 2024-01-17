#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, int n) {
    for (int i = !(1 & arr.size()); i < arr.size(); i += 2)
        arr[i] += n;
    return arr;
}