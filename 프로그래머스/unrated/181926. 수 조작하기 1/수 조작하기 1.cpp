#include <string>
using namespace std;

int solution(int n, string control) {
    for (auto c : control) {
        switch (c) {
            case 'a': n -= 10; break;
            case 'd': n += 10; break;
            case 's': --n; break;
            case 'w': ++n; break;
        }
    }
    return n;
}