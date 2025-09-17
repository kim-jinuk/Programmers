#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string str;
    istringstream ss(s);
    vector<int> vec;
    
    while (getline(ss, str, ' ')) {
        vec.push_back(stoi(str));
    }
    
    answer = to_string(*min_element(vec.begin(), vec.end())) + " " + to_string(*max_element(vec.begin(), vec.end()));
    
    return answer;
}