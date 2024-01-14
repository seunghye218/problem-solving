#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babblings) {
    vector<string> ss = {"aya", "ye", "woo", "ma"};
    int answer = 0;
    for (string &babbling : babblings) {
        string_view babbling_v = babbling;
        string_view pre = "";
        while (babbling_v.size()) {
            bool find = false;
            for (string &s : ss) {
                if (s != pre && !babbling_v.find(s)) {
                    pre = s;
                    babbling_v.remove_prefix(s.size());
                    find = 1;
                    break;
                }
            }
            if (!find)
                break;
        }
        if (!babbling_v.size())
            ++answer;
    }
    return answer;
}