#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[1][1] = triangle[0][0];
    
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= triangle[i - 1].size(); ++j) {
            dp[i][j] = triangle[i - 1][j - 1] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            answer = max(answer, dp[i][j]);
        }
    }
    return answer;
}