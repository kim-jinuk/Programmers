// 1부터 N까지 숫자 중 합이 10이 되는 조합 구하기
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> results;
vector<int> selected_nums;

void backtrack(int N, int sum, int start) {
	if (sum == 10) {
		results.push_back(selected_nums);
		return;
	}
	for (int i = start; i <= N; ++i) {
		if (sum + i <= 10) {
			selected_nums.push_back(i);
			backtrack(N, sum + i, i + 1);
			selected_nums.pop_back();
		}
	}
}

vector<vector<int>> solution(int N) {
	backtrack(N, 0, 1);
	return results;
}