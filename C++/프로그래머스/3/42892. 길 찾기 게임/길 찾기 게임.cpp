#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int x, y, id;
    Node* left;
    Node* right;
};

static inline Node* insert_node(Node* root, Node* u) {
    if (!root) return u;
    Node* cur = root;
    while (true) {
        if (u->x < cur->x) {
            if (!cur->left) { cur->left = u; break; }
            cur = cur->left;
        } else {
            if (!cur->right) { cur->right = u; break; }
            cur = cur->right;
        }
    }
    return root;
}

static inline void preorder(Node* u, vector<int>& out) {
    if (!u) return;
    out.push_back(u->id);
    preorder(u->left, out);
    preorder(u->right, out);
}
static inline void postorder(Node* u, vector<int>& out) {
    if (!u) return;
    postorder(u->left, out);
    postorder(u->right, out);
    out.push_back(u->id);
}

static inline void destroy(Node* u) {  // 메모리 정리(선택)
    if (!u) return;
    destroy(u->left);
    destroy(u->right);
    delete u;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    const int n = (int)nodeinfo.size();
    vector<Node*> nodes; nodes.reserve(n);
    for (int i = 0; i < n; ++i) {
        nodes.push_back(new Node{ nodeinfo[i][0], nodeinfo[i][1], i + 1, nullptr, nullptr });
    }

    // y 내림차순, x 오름차순 → 위 레벨부터 삽입
    sort(nodes.begin(), nodes.end(), [](const Node* a, const Node* b){
        if (a->y != b->y) return a->y > b->y;
        return a->x < b->x;
    });

    Node* root = nullptr;
    for (Node* nd : nodes) root = insert_node(root, nd);

    vector<int> pre, post; pre.reserve(n); post.reserve(n);
    preorder(root, pre);
    postorder(root, post);

    // (선택) OJ에선 생략해도 되지만 깔끔하게 정리
    destroy(root);

    return { pre, post };
}
