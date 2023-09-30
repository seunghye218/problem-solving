#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> op) {
    vector<int> answer(2,0);
    set<int>    order_data_struc;
    for (vector<string>::iterator it = op.begin(); it != op.end(); ++it) {
        if ((*it)[0] == 'I') {
            order_data_struc.insert(stoi(it->substr(2)));
        } else if (order_data_struc.size()) {
            if ((*it)[2] == '1') {
                order_data_struc.erase(--order_data_struc.end());
            } else {
                order_data_struc.erase(order_data_struc.begin());
            }
        }
    }
    if (order_data_struc.size()) {
        answer[1] = *order_data_struc.begin();
        answer[0] = *(--order_data_struc.end());
    }
    return answer;
}