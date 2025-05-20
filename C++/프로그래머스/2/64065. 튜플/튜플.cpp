#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> arr;
    int value;
    vector<int> temp;
    unordered_map<int, int> count;
    
    
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == '{') value = 0;
        else if (s[i] == '}') {
            temp.push_back(value);
            arr.push_back(temp);
            temp.clear();
            i++;
        }
        else if (s[i] == ',') {
            temp.push_back(value);
            value = 0;
        }
        else {
            value *= 10;
            value += s[i] - '0';
        }
    }
    
    sort(arr.begin(), arr.end(), [](vector<int> a, vector<int> b) {return a.size() < b.size();});
    
    for (int i = 0; i < arr.size(); ++i) {
        for (int j : arr[i]) {
            if (count[j] != 1) {
                count[j] = 1;
                answer.push_back(j);
                break;
            }
        }
    }
    
    return answer;
}