#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    if (price < 100000)
        return price;
    else if (price < 300000)
        return static_cast<int>(price * 0.95);
    else if (price < 500000)
        return static_cast<int>(price * 0.9);
    else
        return static_cast<int>(price * 0.8);
}