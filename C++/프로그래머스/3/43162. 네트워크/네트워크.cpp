#include <unordered_map>
#include <vector>

using namespace std;

int parent[201];

int findParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node]);
}

void unionNodes(int node1, int node2) {
    int root1 = findParent(node1);
    int root2 = findParent(node2);
    if (root1 != root2) parent[root2] = root1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (computers[i][j]) {
                unionNodes(i, j);
            }
        }
    }
    
    unordered_map<int, bool> networkFound;
    for (int i = 0; i < n; ++i) {
        int root = findParent(i);
        if (!networkFound[root]) {
            answer++;
            networkFound[root] = true;
        }
    }
    
    return answer;
}