#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    string S;
    cin >> N >> K >> S;

    for (char &c : S) {
        if (K == 0)
            break;
        if (c == 'A')
            continue;
        
        int gap = 'Z' - c + 1;
        if (K >= gap) {
            c = 'A';
            K -= gap;
        }
    }

    K %= 26;
    S.back() += K;
    cout << S;
}
