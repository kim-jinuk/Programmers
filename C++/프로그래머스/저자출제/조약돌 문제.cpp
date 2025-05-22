// 3행 N열의 가중치가 있는 배열 arr가 주어진다.
// 이 배열에 다음 규칙을 준수하면서 조약돌을 놓을 때 최대 가중치의 합을 반환하는 solution() 함수를 구현하라.
// 각 열에 조약돌은 적어도 하나는 놓아야 한다.
// 각 조약돌에 바로 인접한 위치에 조약돌을 놓을 수 없다.

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
	int answer = 0;
	int n = arr[0].size();
	vector<vector<int>> dp(4, vector<int>(n, 0));
	for (int i = 0; i < 3; ++i) {
		dp[i][0] = arr[i][0];
	}
	dp[3][0] = arr[0][0] + arr[2][0];

	for (int j = 1; j < n; ++j) {
		dp[0][j] = arr[0][j] + max(dp[1][j - 1], dp[2][j - 1]);
		dp[1][j] = arr[1][j] + max(max(dp[0][j - 1], dp[2][j - 1]), dp[3][j - 1]);
		dp[2][j] = arr[2][j] + max(dp[0][j - 1], dp[1][j - 1]);
		dp[3][j] = arr[0][j] + arr[2][j] + dp[1][j - 1];
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			answer = max(answer, dp[i][j]);
		}
	}

	return answer;
}