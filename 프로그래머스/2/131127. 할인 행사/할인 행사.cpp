#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int i, sale, end_i, end_sale, answer = 0;
    unordered_map<string, int>  want_map;
    for (int i = 0; i < want.size(); ++i)
        want_map[want[i]] = number[i];
    
    for (int i = 0, end_i = discount.size()-10; i <= end_i; ++i) {
        unordered_map<string, int>  check_products(want_map);
        for (int sale = i, end_sale = sale+10; sale < end_sale; ++sale)
            if (check_products.find(discount[sale]) != check_products.end() && 
                !--check_products[discount[sale]])
                check_products.erase(discount[sale]);
        if (check_products.empty())
            ++answer;
    }
    return answer;
}