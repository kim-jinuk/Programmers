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

### �� ���� / �и� ���� (Disjoint Set Union - Union-Find)

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

## �׷��� �˰���

### �� BFS (�ִ� �Ÿ�, ������ġ �׷���)

```cpp
queue<int> q;
vector<bool> visited(N, false);
q.push(0); visited[0] = true;
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

### �� Dijkstra (����ġ �׷������� �ִ� �Ÿ�)

```cpp
vector<int> dist(N, INT_MAX);
dist[0] = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
pq.push({0, 0});

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

## �˰��� ���

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
    return a.first < b.first;          // ����� ���� ����
});
```

### �� �ùķ��̼� (Simulation - �ܼ� ���� ����)

```cpp
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
for (int dir = 0; dir < 4; ++dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
        // ó��
    }
}
```

### �� ���� ��ȹ�� (DP - ��ȭ�� ��� ����ȭ)

```cpp
vector<int> dp(n + 1, 0);
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; ++i)
    dp[i] = dp[i - 1] + dp[i - 2];
```

### �� �׸��� (Greedy - ���� + Ž�� ����)

```cpp
sort(jobs.begin(), jobs.end());
int last_end = 0;
for (auto& [start, end] : jobs) {
    if (start >= last_end) {
        last_end = end; // ����
    }
}
```

### �� �̺� Ž�� (Binary Search)

```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

### �� �� ������ (Two Pointer)

```cpp
int left = 0, sum = 0, count = 0;
for (int right = 0; right < arr.size(); ++right) {
    sum += arr[right];
    while (sum > target) sum -= arr[left++];
    if (sum == target) count++;
}
```

### �� ������ (Prefix Sum)

```cpp
vector<int> prefix(n + 1, 0);
for (int i = 1; i <= n; ++i)
    prefix[i] = prefix[i - 1] + arr[i - 1];
// ������ [l, r] = prefix[r + 1] - prefix[l]
```

### �� �����̵� ������ (Sliding Window - ���� ���� ���� ��)

```cpp
int sum = 0, maxSum = 0;
for (int i = 0; i < k; ++i) sum += arr[i];
maxSum = sum;
for (int i = k; i < arr.size(); ++i) {
    sum += arr[i] - arr[i - k];
    maxSum = max(maxSum, sum);
}
```

---

