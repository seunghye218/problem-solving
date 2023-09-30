#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    for (vector<int>::iterator it_a = A.begin(), it_b = B.begin();
        it_a != A.end(); ++it_a, ++it_b)
        answer += *it_a * *it_b;
    return answer;
}