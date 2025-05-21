#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int x = 1;
    
    while (true) {
        for (int i = 1; i <= x; ++i) {
            int edge = 2 * (x + i - 2);
            if (edge == brown && yellow == (x * i - edge)) return {x, i};
        }
        x++;
    }
}