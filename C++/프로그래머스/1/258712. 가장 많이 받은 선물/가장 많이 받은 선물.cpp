#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

pair<string, string> splitString(const string& str, char delimeter) {
    vector<string> temp;
    pair<string, string> ret;
    string token;
    stringstream ss(str);
    
    while(getline(ss, token, delimeter)) {
        temp.push_back(token);
    }
    ret.first = temp[0];
    ret.second = temp[1];
    
    return ret;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    pair<string, string> from_to;
    vector<int> receive_present(n);
    vector<int> present_index(n);
    vector<vector<int>> gift_matrix(n, vector<int>(n));
    
    for (string temp : gifts) {
        from_to = splitString(temp, ' ');
        auto a = find(friends.begin(), friends.end(), from_to.first);
        auto b = find(friends.begin(), friends.end(), from_to.second);
        gift_matrix[a-friends.begin()][b-friends.begin()]++;
        present_index[a-friends.begin()]++;
        present_index[b-friends.begin()]--;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (gift_matrix[i][j] > gift_matrix[j][i]) receive_present[i]++;
            else if (gift_matrix[i][j] < gift_matrix[j][i]) receive_present[j]++;
            else {
                if (present_index[i] > present_index[j]) receive_present[i]++;
                else if (present_index[i] < present_index[j]) receive_present[j]++;
            }
        }
    }
    
    answer = *max_element(receive_present.begin(), receive_present.end());
    return answer;
}