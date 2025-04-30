#include <vector>

using namespace std;

void mapping(vector<int>& hash, const vector<int>& arr, int target) {
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] > target) continue;
		hash[arr[i]] = 1;
	}
}

bool solution(vector<int> arr, int target) {
	vector<int> hash(target + 1, 0);
	mapping(hash, arr, target);

	for (int i = 0; i < arr.size(); ++i) {
		int num = target - arr[i];
		if (num == arr[i]) continue;
		if (hash[num]) return true;
	}
	return false;
}