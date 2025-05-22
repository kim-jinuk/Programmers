// 3�� N���� ����ġ�� �ִ� �迭 arr�� �־�����.
// �� �迭�� ���� ��Ģ�� �ؼ��ϸ鼭 ���൹�� ���� �� �ִ� ����ġ�� ���� ��ȯ�ϴ� solution() �Լ��� �����϶�.
// �� ���� ���൹�� ��� �ϳ��� ���ƾ� �Ѵ�.
// �� ���൹�� �ٷ� ������ ��ġ�� ���൹�� ���� �� ����.

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