#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> left, right;
    
    for (int i : topping) {
        right[i]++;
    }
    
    for (int i : topping) {
        left[i]++;
        if (--right[i] == 0) right.erase(i);
        if (left.size() == right.size()) answer++;
    }
    
    return answer;
}