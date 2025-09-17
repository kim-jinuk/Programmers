#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() < 2) return vector(1, -1);
    
    arr.erase(min_element(arr.begin(), arr.end()));
    
    return arr;
}