#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) { return a < b;}

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end(), comp);
    
    for (int i : d) {
        if (budget >= i) {
            answer++;
            budget -= i;
        }
    }
    
    return answer;
}