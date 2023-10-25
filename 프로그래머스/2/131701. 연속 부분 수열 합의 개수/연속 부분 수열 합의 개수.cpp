#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> elements) {
    int i, end = elements.size(), answer = 0;
    unordered_set<int>  sum;
    
//  수열들의 합을 해시에 저장.
    for (i = 0; i < end; ++i) {
        for (int j=i,k=elements[j], end2 = end + i - 1;
             j < end2;
             ++j, k += elements[j%end]) {
            sum.insert(k);
        }
    }
//  전체 길이 수열 1개 더함.
    return sum.size() + 1;
}