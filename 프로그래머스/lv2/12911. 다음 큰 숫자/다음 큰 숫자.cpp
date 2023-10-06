#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 2진수 1의 갯수 리턴.
int cnt_bin_one(int n);

//  해결방안 - n에 1씩 더하며 2진수 1의 갯수가 같을 때 리턴.
int solution(int n) {
    int n_one = cnt_bin_one(n);
    while (true) {
        ++n;
        if (cnt_bin_one(n) == n_one)
            return n;
    }
}

int cnt_bin_one(int n) {
    int cnt = 0;
    for (int i = 1; i < n; i <<= 1) {
        if ((i | n) == n)
            ++cnt;
    }
    return cnt;
}