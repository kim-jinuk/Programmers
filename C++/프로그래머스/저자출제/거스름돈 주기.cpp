#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int amount) {
	vector<int> money = { 100, 50, 10, 1 };
	vector<int> answer;
	
	for (int i = 0; i < 4; ++i) {
		int cnt = amount / money[i];
		for (int j = 0; j < cnt; ++j) {
			answer.push_back(money[i]);
		}
		amount = amount % money[i];
	}

	return answer;
}