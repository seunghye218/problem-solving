int solution(int n) {
    int answer = 0, tmp1 = 0, tmp2 = 1;
    for (int i = 0; i < n; ++i) {
        answer = (tmp1 + tmp2) % 1000000007;
        tmp1 = tmp2;
        tmp2 = answer;
    }
    return answer;
}
