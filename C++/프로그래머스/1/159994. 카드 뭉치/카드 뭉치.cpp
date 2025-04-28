#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    queue<string> cards1_q;
    queue<string> cards2_q;
    
    for (string s : cards1) cards1_q.push(s);
    for (string s : cards2) cards2_q.push(s);
    
    for (string s : goal) {
        if (!cards1_q.empty() && cards1_q.front() == s) {
            cards1_q.pop();
        }
        else if (!cards2_q.empty() && cards2_q.front() == s) {
            cards2_q.pop();
        }
        else return "No";
    }
    
    return "Yes";
}