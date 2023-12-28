#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct part {
    int i;
    string head;
    int num;
};

inline pair<string, int> get_head_num(string str) {
    int i = 0;
    for (; i < str.size() && !isdigit(str[i]); ++i)
        if (isalpha(str[i])) str[i] = toupper(str[i]);
    return {string(str.begin(), str.begin() + i), 
            stoi(string(str.begin() + i, str.end()))};
}

vector<string> solution(vector<string> files) {
    vector<part> vp;
    // parsing
    for (int i = 0; i < files.size(); ++i) {
        pair<string, int> p = get_head_num(files[i]);
        vp.push_back({i, p.first, p.second});
    }
    // sort
    sort(vp.begin(), vp.end(), [](part &p1, part &p2) {
        if (p1.head != p2.head)
            return p1.head < p2.head;
        if (p1.num != p2.num)
            return p1.num < p2.num;
        return p1.i < p2.i;
    });
    // convert
    vector<string> answer;
    for (part &p : vp)
        answer.push_back(files[p.i]);
    return answer;
}