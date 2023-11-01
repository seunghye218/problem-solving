#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    deque<string> cache;
    if (cacheSize == 0)
        return cities.size() * 5;
    int answer = 0;
    for (int i = 0; i < cities.size(); ++i) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto find_cache = find(cache.begin(), cache.end(), cities[i]); 
        if (find_cache != cache.end()) {
            cache.erase(find_cache);
            ++answer;
        } else {
            if (cache.size() == cacheSize)
                cache.pop_front();
            answer += 5;
        }
        cache.push_back(cities[i]);
    }
    return answer;
}