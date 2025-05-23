#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool sort_count(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int total = 0;
    vector<pair<int, int>> count;
    unordered_map<int, int> tan_map;
    unordered_set<int> tan_set;
    
    for (int i : tangerine) {
        tan_set.insert(i);
        tan_map[i]++;
    }
    
    for (int i : tan_set) {
        count.push_back({tan_map[i], i});
    }
    
    sort(count.begin(), count.end(), sort_count);
    
    for (const auto& cnt : count) {
        if (total >= k) return answer;
        total += cnt.first;
        answer++;
    }
}