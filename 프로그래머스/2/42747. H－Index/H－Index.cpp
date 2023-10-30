#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int above, below, size = citations.size(), h = 0;
    while (true) {
        above = 0, below = 0;
        for (int i = 0; i < size; ++i) {
                if (citations[i] >= h) ++above;
                if (citations[i] <= h) ++below;
            }
        if (above < h)
            break;
        ++h;
    }
    return h - 1;
}