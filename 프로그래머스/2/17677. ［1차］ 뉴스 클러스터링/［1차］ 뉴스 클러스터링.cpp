#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 예외처리한 두 문자를 set과 map에 추가함
void get_map_set(string& str1, unordered_map<string, int>& s_map, unordered_set<string> &s_set) {
    for (int i = 0, end = str1.size() - 1; i < end; ++i) {
        string s = str1.substr(i, 2);
        // upper
        s[0] = s[0] | 32;
        s[1] = s[1] | 32;
        if (s[0] < 'a' || s[0] > 'z' || 
            s[1] < 'a' || s[1] > 'z')
            continue;
        ++s_map[s];
        s_set.insert(s);
    }
}

int solution(string str1, string str2) {
    unordered_map<string, int>  s1, s2; // 한 문자열의 집합 카운트
    unordered_set<string>  s_set; // 다중집합 집합
    
    get_map_set(str1, s1, s_set);
    get_map_set(str2, s2, s_set);

    int s_product_set = 0;
    int s_union = 0;
    for (auto it = s_set.begin(); it != s_set.end(); ++it) {
        s_product_set += min(s1[*it], s2[*it]);
        s_union += max(s1[*it], s2[*it]);
    }
    if (s_set.size())
        return (int)(65536.0 * s_product_set / s_union);
    return 65536;
}