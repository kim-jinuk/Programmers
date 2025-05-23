#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end(), [](int a, int b){return a < b;});
    
    for (int i : d) {
        if (i > budget) return answer;
        budget -= i;
        answer++;
    }
    return answer;
}