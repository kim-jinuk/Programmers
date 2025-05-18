#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> results;
vector<int> curr;

void backtrack(int N, int sum, int start) {
	if (sum == 10) {
		results.push_back(curr);
		return;
	}

	for (int i = start; i <= N; ++i) {
		if (sum + i <= 10) {
			curr.push_back(i);
			backtrack(N, sum + i, i + 1);
			curr.pop_back();
		}
	}
}

vector<vector<int>> solution(int N) {
	backtrack(N, 0, 1);
	return results;
}