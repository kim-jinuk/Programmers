#include <tuple>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {
	// 그래프, 방문 배열 INF 값으로 초기화
	for (int i = 0; i < MAX_NODES; ++i) {
		fill_n(graph[i], MAX_NODES, INF);
		visited[i] = false;
	}

	// 인접 배열로 그래프 구현
	for (const auto& [from, to, weight] : edges) {
		graph[from][to] = weight;
	}

	vector<int> distances(numNodes, INF);
	distances[start] = 0;

	for (int i = 0; i < numNodes - 1; ++i) {
		int minDistance = INF;
		int closestNode = -1;

		for (int j = 0; j < numNodes; ++j) {
			if (!visited[j] && distances[j] < minDistance) {
				minDistance = distances[j];
				closestNode = j;
			}
		}
		visited[closestNode] = true;

		for (int j = 0; j < numNodes; ++j) {
			int newDistance = distances[closestNode] + graph[closestNode][j];
			if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) {
				distances[j] = newDistance;
			}
		}
	}

	return distances;
}