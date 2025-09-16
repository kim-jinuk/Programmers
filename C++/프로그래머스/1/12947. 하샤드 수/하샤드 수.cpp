#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int k = x;
    int d = 0;
    while (k != 0) {
        d += (k % 10);
        k /= 10;
    }
    
    return (x % d == 0);
}