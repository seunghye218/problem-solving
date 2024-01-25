#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<bool> delete_list2(1001, false);
    for (int n : delete_list)
        delete_list2[n] = true;

    vector<int> answer;
    for (int n : arr)
        if (!delete_list2[n])
            answer.push_back(n);
    return answer;
}