#include <vector>
#include <tuple>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;	// �Ÿ��� ���� ������� ����
	}
};

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {
	// ���� ����Ʈ ����
	vector<vector<pair<int, int>>> adjList(numNodes);
	for (const auto& [from, to, weight] : edges) {
		adjList[from].push_back(make_pair(to, weight));
	}

	vector<int> distances(numNodes, INF);
	distances[start] = 0;

	// �켱���� ť�� ���� ��� �߰�
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