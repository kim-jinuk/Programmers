#include <string>
#include <vector>

using namespace std;

bool is_odd(int x) {
    for (int i = 1; i < 34; ++i) {
        if (i * i > x) return false;
        if (i * i == x) return true;
    }
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; ++i) {
        if (is_odd(i)) answer -= i;
        else answer += i;
    }
    return answer;
}