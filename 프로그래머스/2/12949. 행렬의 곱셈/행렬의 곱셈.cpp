#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int m_size = arr1.size(), n_size = arr2.size(), p_size = arr2[0].size();
    vector<vector<int>> answer(m_size, vector<int>(p_size, 0));
    
    for (int m = 0; m < m_size; ++m)
        for (int p = 0; p < p_size; ++p)
            for (int n = 0; n < n_size; ++n)
                answer[m][p] += arr1[m][n] * arr2[n][p];
    return answer;
}
