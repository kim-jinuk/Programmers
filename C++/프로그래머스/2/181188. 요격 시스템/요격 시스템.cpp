#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int last_end = -1;
    sort(targets.begin(), targets.end(), comp);
    
    for (const auto& t : targets) {
        int start = t[0];
        int end = t[1];
        if (start >= last_end) {
            answer++;
            last_end = end;
        }
    }
    
    return answer;
}