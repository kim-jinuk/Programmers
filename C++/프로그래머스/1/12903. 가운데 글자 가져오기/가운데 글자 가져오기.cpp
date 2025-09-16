#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int n = s.length();
    string answer = "";
    if (n % 2 == 1) answer = s[n / 2];
    else {
        answer = s[n / 2 - 1];
        answer += s[n / 2];
    }
    
    return answer;
}