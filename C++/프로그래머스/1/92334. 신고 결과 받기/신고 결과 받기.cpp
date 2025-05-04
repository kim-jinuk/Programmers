#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    unordered_map<string, unordered_set<string>> report_log;
    unordered_map<string, int> reported_count;
    unordered_map<string, int> stop_list;
    
    for (string s : report) {
        string user;
        string reported;
        stringstream ss(s);
        
        ss >> user >> reported;
        if (report_log[user].find(reported) == report_log[user].end()) {
            report_log[user].insert(reported);
            reported_count[reported]++;
        }
            
        if (reported_count[reported] == k) stop_list[reported] = 1;
    }
    
    for (int i = 0; i < id_list.size(); ++i) {
        int cnt = 0;
        for (string s : report_log[id_list[i]]) {
            if (stop_list[s]) cnt++;
        }
        answer[i] = cnt;
    }
    
    return answer;
}