int solution(int a, int b) {
    if (a & 1 && b & 1)
        return a * a + b * b;
    if (a & 1 || b & 1)
        return 2 * (a + b);
    return a - b < 0 ? b - a : a - b;
}