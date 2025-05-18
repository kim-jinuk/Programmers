#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
int N;

bool is_valid(const vector<int>& cur, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (cur[i] == col || abs(cur[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void dfs(int row, vector<int>& cur) {
    if (row == N) {
        answer++;
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (is_valid(cur, row, col)) {
            cur[row] = col;
            dfs(row + 1, cur);
        }
    }
}

int solution(int n) {
    N = n;
    answer = 0;
    vector<int> cur(n); // cur[row] = col
    dfs(0, cur);
    return answer;
}
