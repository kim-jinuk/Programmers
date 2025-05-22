#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i - 1][j - 1] == 1) {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])); 
            }
            else dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            answer = max(answer, dp[i][j]);
        }
    }

    return answer * answer;
}