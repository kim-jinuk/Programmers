#include <string>
#include <vector>

using namespace std;

vector<int> answer = {-1};
vector<int> Info;
int best_score = 0;

bool isbetter(vector<int> a, vector<int> b) {
    for (int i = 10; i >= 0; --i) {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}

int get_score(const vector<int>& cur) {
    int diff = 0;
    for (int i = 0; i < cur.size(); ++i) {
        if (cur[i] == 0 && Info[i] == 0) continue;
        if (cur[i] > Info[i]) diff += (10 - i);
        else diff -= (10 - i);
    }
    return diff;
}

void dfs(int N, int pos, vector<int> cur) {
    if (N == 0 || pos == 11) {
        cur[10] += N;
        int diff = get_score(cur);
        if (diff <= 0) {
            cur[10] -= N;
            return;
        }
        
        if (best_score < diff || (best_score == diff && isbetter(cur, answer))) {
            best_score = diff;
            answer = cur;
        }

        cur[10] -= N;
        return;
    }
    
    if (N >= Info[pos] + 1) {
        cur[pos] = Info[pos] + 1;
        dfs(N - (Info[pos] + 1), pos + 1, cur);
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