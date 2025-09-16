#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(long long a, long long b) {
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    vector<long long> vec;
    
    while (n != 0) {
        vec.push_back(n % 10);
        n /= 10;
    }
    sort(vec.begin(), vec.end(), compare);
    
    for (long long val : vec) {
        answer *= 10;
        answer += val;
    }
    
    return answer;
}