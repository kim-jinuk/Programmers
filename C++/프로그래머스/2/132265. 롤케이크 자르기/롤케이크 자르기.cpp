#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> left_map, right_map;
    
    for (int i : topping) right_map[i]++;
    
    for (int i = 0; i < topping.size(); ++i) {
        int t = topping[i];
        left_map[t]++;
        if (--right_map[t] == 0) right_map.erase(t);
        if (left_map.size() == right_map.size()) answer++;
    }
    
    return answer;
}