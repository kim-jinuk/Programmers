#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b) {
    return a > b;
}

long long solution(long long n) {
    string str = to_string(n);
    sort(str.begin(), str.end(), compare);
    return stoll(str);
}