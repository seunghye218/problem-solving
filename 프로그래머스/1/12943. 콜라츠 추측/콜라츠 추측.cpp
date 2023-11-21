int solution(int num) {
    long long n = num;
    num = 0;
    while (n != 1) {
        if (n & 1 == 1) n = n * 3 + 1;
        else n >>= 1;
        ++num;
    }
    return num > 500 ? -1 : num;
}