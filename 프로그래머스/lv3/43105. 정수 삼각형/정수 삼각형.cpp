#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



int solution(vector<vector<int>> triangle) {
    // 내려가면서 원소들을 더한 값 중 큰 값을 저장하며 길어지는 벡터를 이용
    vector<int> sum_line(triangle[0]);

    for (int i = 1; i < triangle.size(); ++i) {
        vector<int> tmp_line(sum_line);
        sum_line.clear();
        for (int j = 0; j < triangle[i].size(); ++j) {
            if (j == 0) {                             // 첫 원소
                sum_line.push_back(tmp_line[0] + triangle[i][0]);
            } else if (j + 1 == triangle[i].size()) { // 마지막 원소
                sum_line.push_back(tmp_line[j - 1] + triangle[i][j]);
            } else {                                  // 중간 원소
                sum_line.push_back( // 위 왼쪽, 오른쪽 원소 중 큰 값 저장.
                    max(
                        tmp_line[j - 1] + triangle[i][j],
                        tmp_line[j] + triangle[i][j])
                );
            }
        }
    }
//  가장 큰 값 리턴.
    return *max_element(sum_line.begin(), sum_line.end());
}