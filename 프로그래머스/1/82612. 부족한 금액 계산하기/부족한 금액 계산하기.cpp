using namespace std;

long long solution(int price, int money, int count) {
    long long total = (long long)count * (count + 1) / 2 * price;
    long long diff =  total - money;
    return diff <= 0 ? 0 : diff;
}