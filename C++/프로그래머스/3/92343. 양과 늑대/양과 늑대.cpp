#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> visited, comp;
int n, answer = 0;

void dfs(vector<int> cur) {
    int sheep = 0, wolf = 0;
    for (int c : cur) {
        if (comp[c] == 1) wolf++;
        else sheep++;
    }
    
    if (sheep <= wolf) return;
    
    answer = max(answer, sheep);
    
    for (int i = 0; i < cur.size(); ++i) {
        int node = cur[i];
        for (int g : tree[node]) {
            if (visited[g]) continue;
            visited[g] = true;
            cur.push_back(g);
            dfs(cur);
            cur.pop_back();
            visited[g] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    tree.resize(n);
    visited.resize(n, false);
    comp = info;
    
    for (auto e : edges) {
        tree[e[0]].push_back(e[1]);
    }
    
    visited[0] = true;
    
    dfs({0});
    return answer;
}