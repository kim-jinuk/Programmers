#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    stack<int> st;
    
    for (int i = 0; i < moves.size(); ++i) {
        for (int j = 0; j < n; j++) {
            if (board[j][moves[i] - 1] != 0) {
                int k = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                if (!st.empty() && (st.top() == k)) {
                    st.pop();
                    answer += 2;
                    break;
                }
                st.push(k);
                break;
            }
        }
    }
    
    return answer;
}