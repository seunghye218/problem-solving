#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    static bool arr[200];
    for (int i = 0, i_end = numbers.size() - 1; i < i_end; ++i)
        for (int j = i + 1; j < numbers.size(); ++j)
            arr[numbers[i] + numbers[j]] = true;
    
    vector<int> answer;
    for (int i = 0; i < 200; ++i)
        if (arr[i])
            answer.push_back(i);
    return answer;
}