#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int small = min(a, b);
    int big = max(a, b);
    
    while ((big - small) > 1 || (big % 2) == 1) {
        small = (small + 1) / 2;
        big = (big + 1) / 2;
        answer++;
    }

    return answer;
}