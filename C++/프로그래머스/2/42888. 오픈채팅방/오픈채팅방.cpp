#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> ret;
    string token;
    stringstream ss(str);
    
    while (getline(ss, token, delimiter)) {
        ret.push_back(token);
    }
    
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> userid_name;
    
    for (string s : record) {
        vector<string> cmd = split(s, ' ');
        if (cmd[0] == "Enter") {
            userid_name[cmd[1]] = cmd[2];
        }
        else if (cmd[0] == "Change") {
            userid_name[cmd[1]] = cmd[2];
        }
    }
    
    for (string s : record) {
        vector<string> cmd = split(s, ' ');
        if (cmd[0] == "Enter") {
            answer.push_back(userid_name[cmd[1]] + "님이 들어왔습니다.");
        }
        else if (cmd[0] == "Leave") {
            answer.push_back(userid_name[cmd[1]] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}