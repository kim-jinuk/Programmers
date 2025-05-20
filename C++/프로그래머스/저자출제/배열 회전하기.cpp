// 2차원 배열을 시계 방향으로 90도 n번 회전하는 solution() 함수를 구현
#include <vector>

using namespace std;

vector<vector<int>> rotate_array(const vector<vector<int>>& arr) {
	int n = arr.size();
	vector<vector<int>> rotated_array(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			rotated_array[j][(n - 1) - i] = arr[i][j];
		}
	}
	return rotated_array;
}

vector<vector<int>> solution(vector<vector<int>> arr, int n) {
	vector<vector<int>> answer = arr;

	for (int i = 0; i < n; ++i) {
		answer = rotate_array(answer);
	}
	
	return answer;
}