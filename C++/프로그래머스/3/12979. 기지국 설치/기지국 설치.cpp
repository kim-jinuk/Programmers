#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int coverage = 2 * w + 1;
    int pos = 1;
    int idx = 0;
    
    while (pos <= n) {
        if (idx < stations.size() && pos >= stations[idx] - w) {
            pos = stations[idx] + w + 1;
            ++idx;
        } else {
            ++answer;
            pos += coverage;
        }
    }
    return answer;
}
