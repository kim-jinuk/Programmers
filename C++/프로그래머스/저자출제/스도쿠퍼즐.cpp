#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

bool isValid(int x, int y, int value) {
	int a = x / 3 * 3;
	int b = y / 3 * 3;
	for (int i = 0; i < 9; ++i) {
		if (graph[x][i] == value || graph[i][y] == value) return true;
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (graph[a + i][b + j] == value) return true;
		}
	}

	return false;
}

pair<int, int> find_empty_position() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (graph[i][j] == 0) return { i, j };
		}
	}
	return { -1, -1 };
}

void backtrack() {
	pair<int, int> pos = find_empty_position();
	if (pos.first == -1) return;

	for (int i = 1; i <= 9; ++i) {
		if (isValid(pos.first, pos.second, i)) {
			graph[pos.first, pos.second] = i;
			backtrack();
			if (find_empty_position().first == -1) return;
			graph[pos.first, pos.second] = 0;
		}
	}

}

vector<vector<int>> solution(vector<vector<int>> board) {
	graph = board;
	backtrack();

	return graph;
}