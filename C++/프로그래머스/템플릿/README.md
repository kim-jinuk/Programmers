# C++ 코딩테스트 요약 템플릿.md

---

## 일반 기술

### ■ 배열 (Array)

```cpp
vector<int> arr = {1, 2, 3};
for (int i = 0; i < arr.size(); ++i) cout << arr[i];
```

### ■ 스택 (Stack)

```cpp
stack<int> s; s.push(1); s.pop(); int t = s.top();
```

### ■ 큐 (Queue)

```cpp
queue<int> q; q.push(1); q.pop(); int f = q.front();
```

### ■ 해시 (unordered\_map / unordered\_set)

```cpp
unordered_map<string, int> m; m["apple"] = 3;
unordered_set<int> s; s.insert(10);
```

---

## 구조하는 구성 기능

### ■ 트리 (Tree - DFS)

```cpp
vector<vector<int>> tree;
vector<bool> visited;
void dfs(int node) {
    visited[node] = true;
    for (int next : tree[node])
        if (!visited[next]) dfs(next);
}
```

### ■ 집합 / 분리 집합 (Disjoint Set Union - Union-Find)

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

## 그래프 알고리즘

### ■ BFS (최단 거리, 무가중치 그래프)

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

### ■ Dijkstra (가중치 그래프에서 최단 거리)

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

## 알고리즘 기법

### ■ 백트래킹 (Backtracking)

```cpp
void backtrack(vector<int>& cur, int depth) {
    if (depth == target) {
        // 결과 처리
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

### ■ 정렬 (Sorting)

```cpp
sort(v.begin(), v.end());               // 오름차순
sort(v.begin(), v.end(), greater<>()); // 내림차순
sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return a.first < b.first;          // 사용자 정의 기준
});
```

### ■ 시뮬레이션 (Simulation - 단순 조건 구현)

```cpp
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
for (int dir = 0; dir < 4; ++dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
        // 처리
    }
}
```

### ■ 동적 계획법 (DP - 점화식 기반 최적화)

```cpp
vector<int> dp(n + 1, 0);
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; ++i)
    dp[i] = dp[i - 1] + dp[i - 2];
```

### ■ 그리디 (Greedy - 정렬 + 탐욕 조건)

```cpp
sort(jobs.begin(), jobs.end());
int last_end = 0;
for (auto& [start, end] : jobs) {
    if (start >= last_end) {
        last_end = end; // 선택
    }
}
```

### ■ 이분 탐색 (Binary Search)

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

### ■ 투 포인터 (Two Pointer)

```cpp
int left = 0, sum = 0, count = 0;
for (int right = 0; right < arr.size(); ++right) {
    sum += arr[right];
    while (sum > target) sum -= arr[left++];
    if (sum == target) count++;
}
```

### ■ 누적합 (Prefix Sum)

```cpp
vector<int> prefix(n + 1, 0);
for (int i = 1; i <= n; ++i)
    prefix[i] = prefix[i - 1] + arr[i - 1];
// 구간합 [l, r] = prefix[r + 1] - prefix[l]
```

### ■ 슬라이딩 윈도우 (Sliding Window - 고정 길이 구간 합)

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

