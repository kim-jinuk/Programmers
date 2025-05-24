#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> stk;
    
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && prices[stk.top()] > prices[i]) {
            answer[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    
    while (!stk.empty()) {
        answer[stk.top()] = n - stk.top() - 1;
        stk.pop();
    }
    
    return answer;
}