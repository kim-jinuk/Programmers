// n을 입력 받아 n x n 크기의 2차원 배열을 생성하여 달팽이 수열을 채우는 solution() 함수를 구현
#include <vector>

using namespace std;

bool isWithinRange(int y, int x, int n) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

vector<vector<int>> solution(int n) {
	vector<pair<int, int>> move = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	vector<vector<int>> visited(n, vector<int>(n, 0));
	vector<vector<int>> answer(n, vector<int>(n, 0));
	int x = 0, y = 0, k = 0;
	answer[0][0] = 1;
	visited[0][0] = 1;

	for (int i = 2; i < n * n + 1; ++i) {
		int ny = y + move[k].first;
		int nx = x + move[k].second;
		if (isWithinRange(ny, nx, n) && visited[ny][nx] == 0) {
			y = ny;
			x = nx;
		}
		else {
			k = (k + 1) % 4;
			y += move[k].first;
			x += move[k].second;
		}
		answer[y][x] = i;
		visited[y][x] = 1;
	}

	return answer;
}