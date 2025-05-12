#include <limits>
#include <tuple>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source) {
	vector<vector<pair<int, int>>> graph(num_vertices);

	for (const auto& edge : edges) {
		int from, to, weight;
		tie(from, to, weight) = edge;
		graph[from].push_back({ to, weight });
	}

	vector<int> distance(num_vertices, INF);
	distance[source] = 0;

	for (int i = 0; i < num_vertices; ++i) {
		for (int j = 0; j < num_vertices; ++j) {
			for (const auto& [v, weight] : grpah[j]) {
				if (distance[j] + weight < distance[v]) {
					distance[v] = distance[j] + weight;
				}
			}
		}
	}

	for (int i = 0; i < num_vertices; ++i) {
		for (const auto& [v, weight] : graph[i]) {
			if (distance[i] + weight < distance[v]) {
				return vector<int>(1, -1);
			}
		}
	}

	return distance;
}