#include <string>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int start, int n, const vector<vector<int>>& arr) {
    vector<int> result(n + 1, INF);
    vector<bool> visited(n + 1, false);
    result[start] = 0;
    
    for (int i = 0; i <= n; ++i) {
        int min_value = INF, curr = -1;
        for (int j = 0; j <= n; ++j) {
            if (!visited[j] && result[j] < min_value) {
                min_value = result[j];
                curr = j;
            }
        }
        if (curr == -1) break;
        visited[curr] = true;
        
        for (int j = 0; j <= n; ++j) {
            if (!visited[j] && arr[curr][j] != INF) {
                result[j] = min(result[j], result[curr] + arr[curr][j]);
            }
        }
    }
    
    return result;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    
    for (int i = 0; i <= n; ++i) {
        graph[i][i] = 0;
    }
    
    for (vector<int> f : fares) {
        graph[f[0]][f[1]] = f[2];
        graph[f[1]][f[0]] = f[2];
    }
    
    vector<int> result_s = dijkstra(s, n, graph);
    vector<int> result_a = dijkstra(a, n, graph);
    vector<int> result_b = dijkstra(b, n, graph);
    
    for (int i = 1; i <= n; ++i) {
        if (result_s[i] != INF && result_a[i] != INF && result_b[i] != INF) {
            answer = min(answer, result_s[i] + result_a[i] + result_b[i]);
        }
    }
    
    return answer;
}