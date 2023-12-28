#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

inline string get_head(string str) {
    auto it = str.begin();
    for (; it != str.end() && !isdigit(*it); ++it)
        if (isalpha(*it)) 
            *it = toupper(*it);
    return string(str.begin(), it);
}

inline int get_num(string str) {
    auto it = str.begin();
    for (; it != str.end() && !isdigit(*it); ++it);
    return stoi(string(it, str.end()));
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), [](auto &s1, auto &s2) {
        string h1 = get_head(s1), h2 = get_head(s2);
        if (h1 != h2)
            return h1 < h2;
        return get_num(s1) < get_num(s2);
    });
    return files;
}