// 다익스트라 알고리즘 우선순위 큐 복습
#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <tuple>
#include <unordered_map>

using namespace std;

const int INF = numeric_limits<int>::max();
struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	}
};

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {
	vector<int> distances(numNodes, INF);
	vector<vector<pair<int, int>>> graph(numNodes);
	vector<bool> visited(numNodes, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	
	for (const auto& [from, to, weight] : edges) {
		graph[from].push_back({ to, weight });
	}

	pq.push({ 0, start });
	distances[start] = 0;

	while (!pq.empty()) {
		int minDistance = pq.top().first;
		int minNode = pq.top().second;
		pq.pop();

		if (visited[minNode]) continue;
		visited[minNode] = true;

		for (const auto& a : graph[minNode]) {
			if (distances[a.first] > distances[minNode] + a.second) {
				distances[a.first] = distances[minNode] + a.second;
				pq.push({ distances[a.first], a.first });
			}
		}
	}

	return distances;
}