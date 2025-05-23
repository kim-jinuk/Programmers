#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp_char(const char& a, const char& b) {
    return a > b;
}

long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), comp_char);
    long long answer = stoll(s);
    return answer;
}