#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<char> result;
unordered_set<char> visited;
unordered_map<char, vector<char>> AdjList;

void dfs(char node) {
	visited.insert(node);
	result.push_back(node);

	for (char neighbor : AdjList[node]) {
		if (visited.find(neighbor) == visited.end()) {
			dfs(neighbor);
		}
	}
}

vector<char> solution(vector<pair<char, char>> graph, char start) {
	for (const auto& edge : graph) {
		char u = edge.first;
		char v = edge.second;
		AdjList[u].push_back(v);
	}

	dfs(start);

	return result;
}