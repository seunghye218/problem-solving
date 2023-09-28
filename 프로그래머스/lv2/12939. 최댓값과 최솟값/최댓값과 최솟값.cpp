#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

string solution(string s) {
    stringstream   ss(s);
    string  buf;
    vector<int>  split;
    while (getline(ss, buf, ' ')) {
        split.push_back(stoi(buf));
    }
    pair<vector<int>::iterator,vector<int>::iterator> p = minmax_element(split.begin(), split.end());
    return to_string(*(p.first)) + " " + to_string(*(p.second));
}