#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string solution(vector<int> numbers, string hand) {
    string answer;
    pair<int, int> L = {0, 3}, R = {2, 3};
    static int pos[11] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
    hand[0] = toupper(hand[0]);
    
    for (int &n : numbers) {
        int x = n ? n % 3 : 2;
        int y = pos[n];
        switch (x) {
            case 0 : 
                answer += 'R';
                R = {2, y};
                break;
            case 1 :
                answer += 'L';
                L = {0, y};
                break;
            default :
                int diff_L = abs(y - L.Y) + abs(1 - L.X);
                int diff_R = abs(y - R.Y) + abs(1 - R.X);
                if (diff_L == diff_R)
                    answer += hand[0];
                else
                    answer += diff_L < diff_R ? 'L' : 'R';    
                (answer.back() == 'L' ? L : R) = {1, y};
        }
    }
    return answer;
}