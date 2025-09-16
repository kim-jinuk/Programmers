#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int m = 1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            answer *= 10;
            answer += (s[i] - '0');
        }
        else if (s[i] == '-') m = -1;
    }
    
    return answer * m;
}