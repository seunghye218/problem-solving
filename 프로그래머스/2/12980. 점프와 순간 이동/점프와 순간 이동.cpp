using namespace std;

// (+1) 하고 (<< 1) 만큼 최대한 이동하는 방식으로 n을 뺀다고 생각하면 
// 주어진 수의 1인 비트 갯수 만큼 빼게 된다.
// 결국 주어진 수의 비트를 세는 문제.
int solution(int n) {
    int cnt = 0;
    while (n) {
        n &= (n - 1);
        ++cnt;
    };
    return cnt;
}