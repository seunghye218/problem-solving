#include <string>
#include <vector>
#include <cstring>

using namespace std;

string solution(string my_string, string letter) {
    char *s;
    while ((s = strstr(my_string.c_str(), letter.c_str())))
        my_string.erase(s - my_string.c_str(), letter.size());
    return my_string;
}