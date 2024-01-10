int count_divisors(int n) {
    int count = 0, i = 1;
    for (; i * i < n; i++)
        if (n % i == 0)
            count += 2;
    if (i * i == n)
        ++count;
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i = 1; i <= number; ++i) {
        int divisors = count_divisors(i);
        answer += divisors > limit ? power : divisors;
    }
    return answer;
}