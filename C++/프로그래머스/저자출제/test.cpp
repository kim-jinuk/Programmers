#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <tuple>

using namespace std;

int INF = numerical_limits<int>::max();
int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

vector<int> solution(int start, int nodeNums, vector<tuple<int, int, int>> edges) {
	for (int i = 0; i < MAX_NODES; ++i) {
		fill_n(graph[i], MAX_NODES, INF);
		visited[i] = false;
	}

	for (const auto& [from, to, weight] : edges) {
		graph[from][to] = weight;
	}

	vector<int> answer(nodeNums, INF);
	answer[start] = 0;

	for (int i = 0; i < nodeNums - 1; ++i) {
		int minDistance = INF;
		int minNode = -1;

		for (int j = 0; j < nodeNums; ++j) {
			if (!visited[j] && minDistance > answer[j]) {
				minDistance = answer[j];
				minNode = j;
			}
		}

		visited[minNode] = true;
		for (int j = 0; j < nodeNums; ++j) {
			int newMinDistance = minDistance + graph[minNode][j];
			if (!visited[j] && graph[minNode][j] != INF && answer[j] > newMinDistance) {
				answer[j] = newMinDistance;
			}
		}
	}

	return answer;
}