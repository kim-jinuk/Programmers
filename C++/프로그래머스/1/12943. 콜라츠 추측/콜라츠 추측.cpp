#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long num2 = num;
    int answer = 0;
    while (num2 != 1) {
        if (answer > 500) return -1;
        answer++;
        
        if (num2 % 2 == 0) num2 /= 2;
        else {num2 = num2 * 3 + 1;}
    }
    return answer;
}