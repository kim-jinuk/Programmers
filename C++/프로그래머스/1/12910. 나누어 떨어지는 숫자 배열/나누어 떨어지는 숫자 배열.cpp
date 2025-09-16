#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); ++i) {
        int x = arr[i];
        while (x >= divisor) {
            x -= divisor;
            if (x == 0) answer.push_back(arr[i]);
        }
    }
    
    sort(answer.begin(), answer.end(), [](int a, int b){return a < b;});
    
    if (answer.empty()) answer.push_back(-1);
    return answer;
}