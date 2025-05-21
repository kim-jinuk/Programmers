// 주어진 두 개의 문자열 str1과 str2에 대해 최장 공통 부분 수열을 반환하는 solution() 함수 구현
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string str1, string str2) {
	string answer;
	int n = str1.size();
	int m = str2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (str1[i] == str2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	// 역추적 (i=n, j=m에서 시작)
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (str1[i - 1] == str2[j - 1]) {
			answer = str1[i - 1] + answer;
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;  // 위쪽으로 이동
		}
		else {
			j--;  // 왼쪽으로 이동
		}
	}

	return answer;
}