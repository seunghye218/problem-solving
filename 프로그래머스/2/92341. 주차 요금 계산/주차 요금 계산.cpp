#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define MAX_TIME 1439

int cul_fee(vector<int> &fees, int time) {
    int fee = fees[1];
    if (time > fees[0]) {
        fee += fees[3];
        fee += (time - fees[0] - 1) / fees[2]  * fees[3];
    }
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, vector<int>>  car_datas;
    map<string, int> car_fees;
    
    // 파싱
    for (auto record : records) {
        auto it = record.begin();
        string car = string(it + 6, it + 6 + 4);
        int time = stoi(string(it, it + 2)) * 60 + stoi(string(it + 3, it + 5));
        car_datas[car].push_back(time);
    }
    // 요금 계산
    for (auto car_data : car_datas) {
        int in_time = 0;
        for (auto it = car_data.second.begin()+1; it <= car_data.second.end(); it += 2) {
            if (it == car_data.second.end()) {
                in_time += MAX_TIME - *(it - 1);
            } else {
                in_time += *it - *(it - 1);
            }
        }
        car_fees[car_data.first] = cul_fee(fees, in_time);
    }
    // 정렬
    for (auto car_fee : car_fees) {
        answer.push_back(car_fee.second);
    }
    return answer;
}