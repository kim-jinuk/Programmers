#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int answer = 0;
vector<bool> visited;
vector<int> comp;
unordered_map<int, vector<int>> graph;

void dfs(vector<int> current) {
    int sheep = 0;
    int wolf = 0;
    for (int i : current) {
        if (comp[i] == 1) wolf++;
        else sheep++;
    }
    
    if (sheep <= wolf) return;
    answer = max(answer, sheep);
    
    for (int i = 0; i < current.size(); ++i) {
        int node = current[i];
        for (int j : graph[node]) {
            if (visited[j]) continue;
            visited[j] = true;
            current.push_back(j);
            dfs(current);
            current.pop_back();
            visited[j] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    visited.resize(info.size(), false);
    comp = info;
    
    for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    visited[0] = true;
    dfs({0});
    
    return answer;
}