#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int N, int W, const vector<int>& weights, const vector<int>& values) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; ++i) {
        int w = weights[i - 1];
        int v = values[i - 1];

        for (int j = 0; j <= W; ++j) {
            if (j < w)
                dp[i][j] = dp[i - 1][j];  // 현재 아이템 못 넣음
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);  // 넣을지 말지 결정
        }
    }

    return dp[N][W];  // 최대 무게 W일 때 최대 가치
}

int main() {
    int N = 4;  // 아이템 수
    int W = 7;  // 배낭 최대 무게
    vector<int> weights = { 6, 4, 3, 5 };  // 각 아이템 무게
    vector<int> values = { 13, 8, 6, 12 }; // 각 아이템 가치

    int max_value = knapsack(N, W, weights, values);
    cout << "최대 가치: " << max_value << endl;

    return 0;
}
