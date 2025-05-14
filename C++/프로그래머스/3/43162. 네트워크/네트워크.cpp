#include <string>
#include <vector>

using namespace std;

void dfs(int i, vector<int>& visited, const vector<vector<int>>& computers) {
    visited[i] = 1;
    
    for (int j = 0; j < computers[i].size(); ++j) {
        if (computers[i][j] == 1 && visited[j] == 0) {
            dfs(j, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n, 0);
    
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            dfs(i, visited, computers);
            answer++;
        }
    }
    
    return answer;
}