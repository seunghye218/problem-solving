#include <vector>
using namespace std;

vector<int> solution(vector<int> num_list) {
    int last = num_list.back(), pre = *(num_list.end() - 2);
    num_list.push_back(last > pre ? last - pre : last << 1);
    return num_list;
}