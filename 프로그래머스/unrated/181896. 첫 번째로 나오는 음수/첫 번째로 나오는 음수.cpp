#include <vector>
using namespace std;

int solution(vector<int> num_list) {
    int i = 0, size = num_list.size();
    for (; i < size; ++i)
        if (num_list[i] < 0)
            break ;
    return i != size ? i : -1;
}