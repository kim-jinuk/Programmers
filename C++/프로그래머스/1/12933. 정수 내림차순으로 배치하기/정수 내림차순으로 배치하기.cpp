#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> temp;
    while(n != 0) {
        int a = n % 10;
        temp.push_back(a);
        n /= 10;
    }
    sort(temp.begin(), temp.end(), [](int a, int b) {return a > b;});
    for (int i = 0; i < temp.size(); ++i) {
        answer *= 10;
        answer += temp[i];
    }
    
    return answer;
}