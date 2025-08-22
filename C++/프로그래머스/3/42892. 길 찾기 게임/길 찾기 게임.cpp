#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, id;
    int left = -1, right = -1;
};

void preorder(const vector<Node>& a, int u, vector<int>& out){
    if (u == -1) return;
    out.push_back(a[u].id);
    preorder(a, a[u].left, out);
    preorder(a, a[u].right, out);
}
void postorder(const vector<Node>& a, int u, vector<int>& out){
    if (u == -1) return;
    postorder(a, a[u].left, out);
    postorder(a, a[u].right, out);
    out.push_back(a[u].id);
}

int insert_node(vector<Node>& a, int root, int u){
    int cur = root;
    while (true) {
        if (a[u].x < a[cur].x) {
            if (a[cur].left == -1) { a[cur].left = u; break; }
            cur = a[cur].left;
        } else {
            if (a[cur].right == -1) { a[cur].right = u; break; }
            cur = a[cur].right;
        }
    }
    return root;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int n = (int)nodeinfo.size();
    vector<Node> nodes; nodes.reserve(n);
    for (int i = 0; i < n; ++i)
        nodes.push_back({nodeinfo[i][0], nodeinfo[i][1], i+1, -1, -1});

    // y 내림차순, x 오름차순
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){
        if (nodes[a].y != nodes[b].y) return nodes[a].y > nodes[b].y;
        return nodes[a].x < nodes[b].x;
    });

    int root = ord[0];
    for (int k = 1; k < n; ++k)
        root = insert_node(nodes, root, ord[k]);

    vector<int> pre, post;
    pre.reserve(n); post.reserve(n);
    preorder(nodes, root, pre);
    postorder(nodes, root, post);
    return {pre, post};
}
