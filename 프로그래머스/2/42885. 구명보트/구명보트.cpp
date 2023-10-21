#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int i, j, alone_limit, answer = 0;
    sort(people.begin(), people.end());

//  혼자 탈 수 밖에 없는 사람 제외
    alone_limit = limit - people[0];
    for (i = people.size() - 1; i >= 0 && people[i] > alone_limit; --i, ++answer);
//  둘이 or 혼자 탈 때
    for (j = 0; j < i; --i, ++answer)
        if (people[j] + people[i] <= limit)
            ++j;
//  혼자 남았을 때
    if (i == j)
        ++answer;
    return answer;
}