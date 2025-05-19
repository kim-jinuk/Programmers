#include <string>
#include <vector>

using namespace std;

vector<int> answer = {-1};
vector<int> Info;
int best_score = 0;

int get_score(const vector<int>& cur) {
    int ryan = 0, apeach = 0;
    for (int i = 0; i < cur.size(); ++i) {
        if (cur[i] == 0 && Info[i] == 0) continue;
        if (cur[i] > Info[i]) ryan += (10 - i);
        else apeach += (10 - i);
    }
    return ryan - apeach;
}

bool is_better(const vector<int>& a, const vector<int>& b) {
    for (int i = 10; i >= 0; --i) {
        if (a[i] != b[i]) return a[i] > b[i];
    }
}

void dfs(int N, int pos, vector<int> cur) {
    if (N == 0 || pos == 11) {
        if (N > 0) cur[10] += N;
        int diff = get_score(cur);
        if (diff > 0) {
            if (diff > best_score) {
                best_score = diff;
                answer = cur;
            }
            else if (diff == best_score && is_better(cur, answer)) {
                answer = cur;
            }
        }
        if (N > 0) cur[10] -= N;
        return;
    }
    
    if (N > Info[pos]) {
        cur[pos] = Info[pos] + 1;
        dfs(N - cur[pos], pos + 1, cur);
        cur[pos] = 0;
    }
    dfs(N, pos + 1, cur);
}

vector<int> solution(int n, vector<int> info) {
    Info = info;
    vector<int> cur(info.size(), 0);
    dfs(n, 0, cur);
    
    return answer;
}