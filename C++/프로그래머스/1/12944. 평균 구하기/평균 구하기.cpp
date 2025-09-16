#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int size = arr.size();
    for (int value : arr) {
        answer += value;
    }
    return answer / size;
}