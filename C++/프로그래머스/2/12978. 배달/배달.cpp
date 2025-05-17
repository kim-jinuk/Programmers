#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_set<int> answer;
unordered_map<int, vector<pair<int, int>>> graph;
vector<bool> visited;

struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

void bfs(const int& k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;
    
    q.push({0, 0});
    while (!q.empty()) {
        int time = q.top().first;
        int node = q.top().second;
        q.pop();
        visited[node] = true;
        answer.insert(node);
        
        for (const auto& a : graph[node]) {
            if (!visited[a.first] && a.second + time <= k) {
                q.push({a.second + time, a.first});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    for (const auto& a : road) {
        graph[a[0] - 1].push_back({a[1] - 1, a[2]});
        graph[a[1] - 1].push_back({a[0] - 1, a[2]});
    }
    visited.resize(N, false);
    
    answer.insert(0);
    visited[0] = true;
    
    bfs(K);
    
    return answer.size();
}