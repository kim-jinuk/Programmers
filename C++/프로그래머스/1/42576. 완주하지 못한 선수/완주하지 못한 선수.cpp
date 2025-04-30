#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> complete_list;
    
    for (string s : participant) complete_list[s] += 1;
    for (string s : completion) complete_list[s] -= 1;
    for (string s : participant) {
        if (complete_list[s] > 0) return s;
    }
    
}