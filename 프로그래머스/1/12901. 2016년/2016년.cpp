#include <string>
#include <ctime>

using namespace std;

string solution(int a, int b) {
    char *dayOfWeek[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    tm tm {};
    tm.tm_year = 2016 - 1900;
    tm.tm_mon = a - 1;
    tm.tm_mday = b;
    std::mktime(&tm);
    return dayOfWeek[tm.tm_wday];
}