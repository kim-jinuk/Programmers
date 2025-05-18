#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<bool> visited;
vector<vector<int>> graph;

void dfs(int hp, int cnt) {
    answer = max(answer, cnt);
    
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i] && graph[i][0] <= hp) {
            visited[i] = true;
            dfs(hp - graph[i][1], cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    graph = dungeons;
    visited.resize(graph.size(), false);
    
    dfs(k, 0);
    
    return answer;
}