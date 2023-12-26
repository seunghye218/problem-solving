#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> foods) {
    string answer = "";
    // 왼쪽 음식
    for (int food = 0; food < foods.size(); ++food) {
        if ((foods[food] /= 2)) {
            for (int count = 0; count < foods[food]; ++count)
                answer += '0' + food;
        }
    }
    answer += '0'; // 물
    // 오른쪽 음식
    string right_food(answer.begin(), answer.end() - 1);
    reverse(right_food.begin(), right_food.end());
    answer += right_food;
    return answer;
}