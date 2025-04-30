#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> word_set;
    word_set.insert(words[0]);
    
    for (int i = 1; i < words.size(); ++i) {
        answer[0] = i % n + 1;
        answer[1] = (i / n) + 1;
        
        if (word_set.find(words[i]) != word_set.end()) return answer;
        word_set.insert(words[i]);
        
        if (words[i][0] != words[i-1][words[i-1].size()-1]) return answer;
    }
    
    return vector<int> (2, 0);
}