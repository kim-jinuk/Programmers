# Ƽ�� �������� ���� C++ �ڵ��׽�Ʈ ��� ��Ź�.md

---

## �Ϲ� ���

### �� �迭 (Array)

```cpp
vector<int> arr = {1, 2, 3};
for (int i = 0; i < arr.size(); ++i) cout << arr[i];
```

### �� ���� (Stack)

```cpp
stack<int> s; s.push(1); s.pop(); int t = s.top();
```

### �� ť (Queue)

```cpp
queue<int> q; q.push(1); q.pop(); int f = q.front();
```

### �� �ؽ� (unordered\_map / unordered\_set)

```cpp
unordered_map<string, int> m; m["apple"] = 3;
unordered_set<int> s; s.insert(10);
```

---

## �����ϴ� ���� ���

### �� Ʈ�� (Tree - DFS)

```cpp
vector<vector<int>> tree;
vector<bool> visited;
void dfs(int node) {
    visited[node] = true;
    for (int next : tree[node])
        if (!visited[next]) dfs(next);
}
```

### �� ���� / �̸� �з� (Disjoint Set)

```cpp
vector<int> parent;
int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a != b) parent[b] = a;
}
```

---

## �׷����� ���ͽ�Ʈ��

### �� BFS (Queue + visited)

```cpp
queue<int> q;
vector<bool> visited(N + 1, false);
q.push(1); visited[1] = true;
while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int next : graph[cur]) {
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
        }
    }
}
```

### �� Dijkstra (priority\_queue + distance)

```cpp
vector<int> dist(N + 1, INT_MAX);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
dist[1] = 0; pq.push({0, 1});
while (!pq.empty()) {
    auto [cost, node] = pq.top(); pq.pop();
    if (cost > dist[node]) continue;
    for (auto [weight, next] : graph[node]) {
        int new_cost = cost + weight;
        if (new_cost < dist[next]) {
            dist[next] = new_cost;
            pq.push({new_cost, next});
        }
    }
}
```

---

### �� ��Ʈ��ŷ (Backtracking)

```cpp
void backtrack(vector<int>& cur, int depth) {
    if (depth == target) {
        // ��� ó��
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        used[i] = true;
        cur.push_back(i);
        backtrack(cur, depth + 1);
        cur.pop_back();
        used[i] = false;
    }
}
```

### �� ���� (Sorting)

```cpp
sort(v.begin(), v.end());               // ��������
sort(v.begin(), v.end(), greater<>()); // ��������
sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return a.first < b.first;          // ���� ����
});
```

### �� �ùķ��̼� (Simulation - ��¥, �׷��� ����)

```cpp
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
for (int dir = 0; dir < 4; ++dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    // ���� üũ, ó��
}
```

### �� ���� ��ȹ�� (DP)

```cpp
vector<int> dp(n + 1, 0);
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; ++i)
    dp[i] = dp[i - 1] + dp[i - 2];
```

### �� �׸��� (Greedy)

```cpp
sort(tasks.begin(), tasks.end());
for (auto& [start, end] : tasks) {
    if (end > last_end) {
        // ���� 
        last_end = end;
    }
}
```

---

