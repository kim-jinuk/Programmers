#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    while (num != 1) {
        if (answer > 400) return -1;
        answer++;
        
        if (num % 2 == 0) num /= 2;
        else {num = num * 3 + 1;}
    }
    return answer;
}