// 두 행렬을 곱한 결과에 전치 행렬 적용하기
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> matrix1, vector<vector<int>> maxrix2) {
	vector<vector<int>> answer(3, vector<int>(3, 0));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				answer[j][i] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return answer;
}