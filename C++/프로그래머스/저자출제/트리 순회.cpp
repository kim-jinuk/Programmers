#include <string>
#include <vector>
#include <iostream>

using namespace std;

string preorder(vector<int> nodes, int idx) {
	if (idx < nodes.size()) {
		string ret = to_string(nodes[idx]) + " ";
		ret += preorder(nodes, idx * 2);
		ret += preorder(nodes, idx * 2 + 1);
		return ret;
	}
	return "";
}

string inorder(vector<int> nodes, int idx) {
	if (idx < nodes.size()) {
		string ret = inorder(nodes, idx * 2);
		ret += to_string(nodes[idx]) + " ";
		ret += inorder(nodes, idx * 2 + 1);
		return ret;
	}

	return "";
}

string postorder(vector<int> nodes, int idx) {
	if (idx < nodes.size()) {
		string ret = postorder(nodes, idx * 2);
		ret += postorder(nodes, idx * 2 + 1);
		ret += to_string(nodes[idx]) + " ";
	}
	return "";
}

vector<string> solution(vector<int> nodes) {
	vector<string> answer;
	nodes.insert(nodes.begin(), -1);
	
	answer.push_back(preorder(nodes, 1));
	answer.push_back(inorder(nodes, 1));
	answer.push_back(postorder(nodes, 1));

	for (string s : answer) cout << s << endl;

	return answer;
}
