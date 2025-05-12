#include <vector>
#include <tuple>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;	// 거리가 작은 순서대로 정렬
	}
};

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {
	// 인접 리스트 생성
	vector<vector<pair<int, int>>> adjList(numNodes);
	for (const auto& [from, to, weight] : edges) {
		adjList[from].push_back(make_pair(to, weight));
	}

	vector<int> distances(numNodes, INF);
	distances[start] = 0;

	// 우선순위 큐에 시작 노드 추가
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	pq.push({ 0, start });

	vector<bool> visited(numNodes, false);

	while (!pq.empty()) {
		int currentDistance = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (visited[currentNode]) continue;
		visited[currentNode] = true;

		for (const auto& [neighbor, weight] : adjList[currentNode]) {
			int newDistance = distances[currentNode] + weight;
			if (newDistance < distances[neighbor]) {
				distances[neighbor] = newDistance;
				pq.push({ newDistance, neighbor });
			}
		}
	}

	return distances;
}