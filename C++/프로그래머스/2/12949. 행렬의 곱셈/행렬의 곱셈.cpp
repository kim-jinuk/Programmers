#include <string>
#include <vector>

using namespace std;

int matrix_mul(const vector<vector<int>>& arr1, const vector<vector<int>>& arr2, int a, int b) {
    int n = arr2.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr1[a][i] * arr2[i][b];
    }
    return sum;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int m = arr1.size();
    int n = arr2[0].size();
    vector<vector<int>> answer(m);
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            answer[i].push_back(matrix_mul(arr1, arr2, i, j));
        }
    }
    
    return answer;
}