#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    for (vector<int>::iterator it = array.begin(); it != array.end();++it)
        if (*it > height)
            ++answer;
    return answer;
}