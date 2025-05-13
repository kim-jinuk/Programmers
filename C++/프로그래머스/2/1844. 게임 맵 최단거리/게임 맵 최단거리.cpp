#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Point {
    int y, x, cnt;
};

int n, m;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool isWithinRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int bfs(const vector<vector<int>>& maps) {
    queue<Point> q;
    bool visited[100][100] = {false};
    
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        if (current.y == n - 1 && current.x == m - 1) return current.cnt;
        
        for (int i = 0; i < 4; ++i) {
            int ny = current.y + dy[i];
            int nx = current.x + dx[i];
            
            if (isWithinRange(ny, nx) && !visited[ny][nx] && maps[ny][nx] == 1) {
                q.push({ny, nx, current.cnt + 1});
                visited[ny][nx] = true;
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int distance;
    
    n = maps.size();
    m = maps[0].size();
    
    distance = bfs(maps);
    
    return distance;
}