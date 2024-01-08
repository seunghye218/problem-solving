#include <vector>
using namespace std;

vector<bool> arr(3000, true);

bool isprime(int n) {
    if (n < 2)
        return false;
    if (arr[0]) {
        for (int i = 2; i <= 3000; i++)
            if (arr[i])
                for (int j = i * i; j <= 3000; j += i)
                    arr[j] = false;
        arr[0] = false;
    }
    return arr[n];
}

int solution(vector<int> nums) {
    int answer = 0;
    for (int i = 2; i < nums.size(); ++i)
        for (int j = i - 1; j >= 1; --j)
            for (int k = j - 1; k >= 0; --k)
                answer += isprime(nums[i] + nums[j] + nums[k]);
    return answer;
}