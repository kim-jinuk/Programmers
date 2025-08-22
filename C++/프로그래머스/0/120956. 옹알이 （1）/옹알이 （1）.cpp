#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const vector<string> samples = {"aya", "ye", "woo", "ma"};

bool can_speak(const string& s) {
    string t = s;
    for (const string& w : samples) {
        size_t p = t.find(w);
        if (p != string::npos) t.replace(p, w.size(), " ");
    }
    t.erase(remove(t.begin(), t.end(), ' '), t.end());
    return t.empty();
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (const string& str : babbling) {
        if (can_speak(str)) answer++;
    }
    
    return answer;
}