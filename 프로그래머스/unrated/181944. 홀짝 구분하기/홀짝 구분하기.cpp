#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    cout << n << " is "s + (n & 1 ? "odd" : "even");
    return 0;
}