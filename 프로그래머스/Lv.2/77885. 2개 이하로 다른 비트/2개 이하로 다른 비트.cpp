#include <vector>
#include <bitset>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    for (long long &n : numbers) {
        bitset<64> bs(n);
        if (n < 2) {
            ++n; continue;
        }
        int top_true = 63, bottom_false = 0;
        while (!bs[top_true])
            --top_true;
        while (bs[bottom_false])
            ++bottom_false;
        bs.set(bottom_false);
        if (bottom_false) {
            while (--bottom_false && !bs[bottom_false]);
            bs.reset(bottom_false);
        }
        n = bs.to_ullong();
    }
    return numbers;
}