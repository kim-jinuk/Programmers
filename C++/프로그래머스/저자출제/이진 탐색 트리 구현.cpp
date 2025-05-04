#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BST {
private:
	Node* root;

	Node* insertNode(Node* node, int key) {
		if (!node) {
			return new Node(key);
		}

		if (key < node->val) {
			node->left = insertNode(node->left, key);
		}
		else {
			node->right = insertNode(node->right, key);
		}
		return node;
	}

	bool searchNode(Node* node, int key) {
		if (!node) {
			return false;
		}

		if (key == node->val) {
			return true;
		}
		return key < node->val ? searchNode(node->left, key) : searchNode(node->right, key);
	}

public:
	BST() : root(nullptr) {}
	void insert(int key) {
		root = insertNode(root, key);
	}

	bool search(int key) {
		return searchNode(root, key);
	}
};

vector<bool> solution(vector<int> lst, vector<int> search_lst) {
	BST bst;
	vector<bool> result;

	for (int key : lst) bst.insert(key);

	for (int search_val : search_lst) result.push_back(bst.sesarch(search_val));

	return result;
}