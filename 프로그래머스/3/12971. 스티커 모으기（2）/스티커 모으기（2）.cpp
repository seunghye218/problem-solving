#include <vector>
#include <algorithm>
using namespace std;

int dp(const int &start, vector<int> dp) {
    int len = dp.size(), i = 1;

//  시작 인덱스에 따른 초기화
    if (start) ++i;
    else --len;
    dp[i] = max(dp[i], dp[i - 1]);
    ++i;
    for (; i < len; ++i)
        dp[i] = max(dp[i-1], dp[i-2] + dp[i]);
    return max(dp[len - 1], dp[len - 2]);
}

int solution(vector<int> sticker) {
    return max(dp(0, sticker), dp(1, sticker));
}