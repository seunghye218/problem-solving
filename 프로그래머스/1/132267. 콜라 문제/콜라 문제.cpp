int solution(int a, int b, int n) {
    return n < a ? 0 : solution(a, b, n / a * b + n % a) + (n / a) * b;
}