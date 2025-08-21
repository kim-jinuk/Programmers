#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> matchCnt(3);
    
    vector<int> math_1 = {1, 2, 3, 4, 5};
    vector<int> math_2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> math_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == math_1[i % math_1.size()]) matchCnt[0]++;
        if (answers[i] == math_2[i % math_2.size()]) matchCnt[1]++;
        if (answers[i] == math_3[i % math_3.size()]) matchCnt[2]++;
    }
    
    int max_value = *max_element(matchCnt.begin(), matchCnt.end());
    
    for (int i = 0; i < 3; ++i) {
        if (matchCnt[i] == max_value) answer.push_back(i + 1);
    }
    
    return answer;
}