// 주어진 두 개의 문자열 str1과 str2에 대해 최장 공통 부분 수열의 길이를 반환하는 solution() 함수 구현
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string str1, string str2) {
	int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (str1[i] == str2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	return dp[n][m];
}