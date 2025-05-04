#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void dfs(string src, string dst, int depth, map<string, int>& combi) {
    if (dst.size() == depth) combi[dst]++;
    else {
        for (int i = 0; i < src.size(); ++i) {
            dfs(src.substr(i + 1), dst + src[i], depth, combi);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> combi;
    
    for (int i : course) {
        int maxOrder = 0;
        for (string s : orders) {
            sort(s.begin(), s.end());
            dfs(s, "", i, combi);
        }
        
        for (auto it : combi) {
            maxOrder = max(maxOrder, it.second);
        }
        for (auto it : combi) {
            if (maxOrder >= 2 && it.second == maxOrder) answer.push_back(it.first);
        }
        combi.clear();
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}