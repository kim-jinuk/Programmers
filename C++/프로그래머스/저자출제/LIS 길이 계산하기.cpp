// 정수 배열 nums에서 LIS의 길이를 반환하는 solution() 함수를 구현
#include <iostream>
#include <vector>

using namespace std;

int solution(const vector<int>& nums) {
	if (nums.empty()) return 0;

	int n = nums.size();
	vector<int> dp(n, 1);
	int answer = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(answer, dp[i]);
	}

	return answer;
}
