#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool sort_string(const string& a, const string& b) {
    if (a[N] == b[N]) return a < b;
    return a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    sort(strings.begin(), strings.end(), sort_string);
    
    return strings;
}